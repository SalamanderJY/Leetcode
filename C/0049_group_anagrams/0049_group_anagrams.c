typedef struct {
    char *key;
    int count;
    int *array;
    UT_hash_handle hh;
} HashEntry;

HashEntry *g_head;

void addHashEntry(char *key, int pos) 
{
    HashEntry *tmp, *addEntry;
    HASH_FIND_STR(g_head, key, tmp);
    // HASH_FIND(hh, g_head, key, strlen(key)*sizeof(char), tmp);
    if (tmp != NULL) {
        tmp->array = (int *)realloc(tmp->array, (tmp->count + 1) * sizeof(int));
        tmp->array[tmp->count++] = pos;
    } 
    else {
        addEntry = (HashEntry *)malloc(sizeof(HashEntry));
        addEntry->array = (int *)malloc(sizeof(int));
        addEntry->array[0] = pos;
        addEntry->count = 1;
        addEntry->key = (char *)malloc((strlen(key) + 1) * sizeof(char));
        memcpy(addEntry->key, key, (strlen(key) + 1) * sizeof(char));
        HASH_ADD_KEYPTR(hh, g_head, addEntry->key, strlen(addEntry->key), addEntry);
    }
}

int cmp(const void *a, const void *b) 
{
    return *(char *)a - *(char *)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
    for (int i = 0; i < strsSize; i++) {
        char *sortedKey = (char *)malloc((strlen(strs[i]) + 1) * sizeof(char));
        memcpy(sortedKey, strs[i], (strlen(strs[i]) + 1) * sizeof(char));
        qsort(sortedKey, strlen(strs[i]), sizeof(char), cmp);
        addHashEntry(sortedKey, i);
        free(sortedKey);
    }

    char ***ret = (char ***)malloc(HASH_COUNT(g_head) * sizeof(char **));
    *returnColumnSizes = (int *)malloc(HASH_COUNT(g_head) * sizeof(int));
    HashEntry *cur, *tmp;
    int count = 0;
    HASH_ITER(hh, g_head, cur, tmp) {
        ret[count] = (char **)malloc(cur->count * sizeof(char *));
        for (int i = 0; i < cur->count; i++) {
            ret[count][i] = (char *)malloc((strlen(cur->key) + 1) * sizeof(char));
            memcpy(ret[count][i], strs[cur->array[i]], (strlen(cur->key) + 1) * sizeof(char));
        }
        (*returnColumnSizes)[count++] = cur->count;
        HASH_DEL(g_head, cur);
        free(cur->array);
        free(cur);
    }
    *returnSize = count;
    return ret;
}