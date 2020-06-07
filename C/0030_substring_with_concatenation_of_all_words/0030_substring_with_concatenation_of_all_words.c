typedef struct hashEntry {
    char *key;
    int cnt;
    int usedCnt;
    UT_hash_handle hh;
} WordNode;

WordNode *map;

void InitMap(char **words, int wordsSize)
{
    map = NULL;
    WordNode *wordNode = NULL;
    int len = strlen(words[0]);
    for (int i = 0; i < wordsSize; i++) {
        HASH_FIND_STR(map, words[i], wordNode);
        if (wordNode == NULL) {
            wordNode = calloc(1, sizeof(WordNode));
            wordNode->key = calloc(len + 1, sizeof(char));
            strcpy(wordNode->key, words[i]);
            wordNode->cnt++;
            HASH_ADD_KEYPTR(hh, map, wordNode->key, len, wordNode);
        }
        else {
            wordNode->cnt++;
        }
    }
}

void ResetMap()
{
    WordNode *wordNode;
    WordNode *tmp;
    HASH_ITER(hh, map, wordNode, tmp) {
        wordNode->usedCnt = 0;
    }
}

void DeleteMap()
{
    WordNode *current;
    WordNode *tmp;
    HASH_ITER(hh, map, current, tmp) {
        HASH_DEL(map, current);
        free(current->key);
        free(current);
    }
}

int *findSubstring(char *s, char** words, int wordsSize, int* returnSize)
{
    if (s == NULL || words == NULL || wordsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    InitMap(words, wordsSize);
    int len = strlen(s);
    int *res = calloc(len, sizeof(int));
    int cnt = 0;
    int wordLen = strlen(words[0]);
    char *tmp = calloc(wordLen + 1, sizeof(char));
    WordNode *wordNode;
    for (int i = 0; i <= len - (wordLen * wordsSize); i++) {
        int j;
        ResetMap();
        for (j = i; j < i + (wordLen * wordsSize); j += wordLen) {
            strncpy(tmp, &s[j], wordLen);
            HASH_FIND_STR(map, tmp, wordNode);
            if (wordNode == NULL || wordNode->usedCnt == wordNode->cnt) {
                break;
            }
            else {
                wordNode->usedCnt++;
            }
        }
        if (j >= i + (wordLen * wordsSize)) {
            res[cnt++] = i;
        }
    }
    DeleteMap();
    free(tmp);
    *returnSize = cnt;
    return res;
}
