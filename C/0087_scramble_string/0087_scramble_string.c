/* memory search array */
/* -1 means false, current substring is not satisfied */
/* 1  means true, current substring is satisfied */
/* 0  means initial */
#define MAX_STRING_LEN  31
int memo[MAX_STRING_LEN][MAX_STRING_LEN][MAX_STRING_LEN];

struct HashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

void modifyHashTable(struct HashTable** hashTable, int x, int inc)
{
    struct HashTable* tmp;
    HASH_FIND_INT(*hashTable, &x, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(struct HashTable));
        tmp->key = x;
        tmp->val = inc;
        HASH_ADD_INT(*hashTable, key, tmp); /* key is self-defined struct "key" which is a variable name */
    } else {
        tmp->val += inc;
    }
}

bool checkHashTable(struct HashTable** hashTable)
{
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        if (iter->val) {
            return false;
        }
    }
    return true;
}

void freeHashTable(struct HashTable** hashTable) 
{
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, *hashTable, iter, tmp) {
        HASH_DEL(*hashTable, iter);
        free(iter);
    }
}

bool equals(char* s1, char* s2, int i1, int i2, int len) 
{
    for (int i = 0; i < len; i++) {
        if (s1[i + i1] != s2[i + i2]) {
            return false;
        }
    }
    return true;
}

/* s1 start from i1, s2 start from i2, and len is length which is satisfied or not */
bool dfs(char *s1, char *s2, int i1, int i2, int length)
{
    if (memo[i1][i2][length] != 0) {
        return memo[i1][i2][length] == 1;
    }

    if (equals(s1, s2, i1, i2, length)) {
        memo[i1][i2][length] = 1;
        return true;
    }

    struct HashTable* hashTable = NULL;
    for (int i = i1; i < i1 + length; ++i) {
        modifyHashTable(&hashTable, s1[i], 1);
    }
    for (int i = i2; i < i2 + length; ++i) {
        modifyHashTable(&hashTable, s2[i], -1);
    }
    if (!checkHashTable(&hashTable)) {
        memo[i1][i2][length] = -1;
        return false;
    }
    freeHashTable(&hashTable);

    /* enum position of cut */
    for (int i = 1; i < length; i++) {
        /* not exchange position */
        if (dfs(s1, s2, i1, i2, i) && dfs(s1, s2, i1 + i, i2 + i, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
        if (dfs(s1, s2, i1, i2 + length - i, i) && dfs(s1, s2, i1 + i, i2, length - i)) {
            memo[i1][i2][length] = 1;
            return true;
        }
    }
    memo[i1][i2][length] = -1;
    return false;
}

/* len(s1) == len(s2) */
bool isScramble(char *s1, char *s2)
{
    memset(memo, 0, sizeof(memo));
    return dfs(s1, s2, 0, 0, strlen(s1));
}