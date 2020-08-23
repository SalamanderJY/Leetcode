void countAndSaySingle(char* str)
{
    char* temp = (char *)malloc(5000 * sizeof(char));
    int index = 0;
    int count = 1;
    for (int i = 1; i < strlen(str); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        }
        else {
            temp[index++] = count + '0';
            temp[index++] = str[i - 1];
            count = 1;
        }
    }
    temp[index++] = count + '0';
    temp[index++] = str[strlen(str) - 1];
    temp[index++] = '\0';
    strcpy(str, temp);
    free(temp);
}

char* countAndSay(int n)
{
    char* res = malloc(5000 * sizeof(char));
    res[0] = '1';
    res[1] = '\0';
    if (n < 1)
        return NULL;
    for (int i = 2; i <= n; i++)
        countAndSaySingle(res);
    return res;
}