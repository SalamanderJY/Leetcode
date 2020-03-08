char* intToRoman(int num) {
    int numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* chars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char* res = (char*)malloc(32 * sizeof(char));
    int index = 0;
    for(int i = 0; num > 0; num %= numbers[i], i++) {
        for(int j = 0, k = num / numbers[i]; j < k; j++) {
            for (int charsIndex = 0; charsIndex < strlen(chars[i]); charsIndex++) {
                res[index] = chars[i][charsIndex];
                index++;
            }
        }

    }
    res[index] = '\0';
    return res;
}