int romanToInt(char * s) {
    int hashmap[256];
    memset(hashmap, 0, sizeof(int) * 256);
    hashmap[(int)('I')] = 1;
    hashmap[(int)('V')] = 5;
    hashmap[(int)('X')] = 10;
    hashmap[(int)('L')] = 50;
    hashmap[(int)('C')] = 100;
    hashmap[(int)('D')] = 500;
    hashmap[(int)('M')] = 1000;
    
    int result = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (i == 0) {
            result += hashmap[s[i]];
        }
        if (i > 0) {
            if (hashmap[s[i]] <= hashmap[s[i - 1]]) {
                result += hashmap[s[i]];
            }
            else {
                result = result - 2 * hashmap[s[i - 1]];
                result += hashmap[s[i]];
            }
        }
    }
    return result;
}