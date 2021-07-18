/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define SEG_COUNT   4

int segments[SEG_COUNT];
char** ans;
int ansLen;

void dfs(char *s, int segId, int segStart)
{
    int lenS = strlen(s);
    /* touch 4 segment */
    if (segId == SEG_COUNT) {
        if (segStart == lenS) {
            char *ipAddr = (char *)malloc(sizeof(char) * (lenS + SEG_COUNT));
            int add = 0;
            for (int i = 0; i < SEG_COUNT; i++) {
                int number = segments[i];
                if (number >= 100) {
                    ipAddr[add++] = number / 100 + '0'; 
                }
                if (number >= 10) {
                    ipAddr[add++] = number % 100 / 10 + '0';
                }
                ipAddr[add++] = number % 10 + '0';
                if (i != SEG_COUNT - 1) {
                    ipAddr[add++] = '.';
                }
            }
            ipAddr[add] = 0;
            ans = realloc(ans, sizeof(char *) * (ansLen + 1));
            ans[ansLen++] = ipAddr;
        }
        return ;
    }

    if (segStart == lenS) {
        return ;
    }

    if (s[segStart] == '0') {
        segments[segId] = 0;
        dfs(s, segId + 1, segStart + 1);
    }

    int addr = 0;
    for (int segEnd = segStart; segEnd < lenS; segEnd++) {
        addr = addr * 10 + (s[segEnd] - '0');
        if (addr > 0 && addr <= 0xFF) {
            segments[segId] = addr;
            dfs(s, segId + 1, segEnd + 1);
        } else {
            break;
        }
    }
}

char** restoreIpAddresses(char *s, int *returnSize)
{
    ans = (char **)malloc(0);
    ansLen = 0;
    dfs(s, 0, 0);
    (*returnSize) = ansLen;
    return ans;
}