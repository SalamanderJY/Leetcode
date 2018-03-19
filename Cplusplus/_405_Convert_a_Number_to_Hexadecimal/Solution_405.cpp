class Solution {
public:
    string toHex(int num) {
        char map[26] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'}; 
        if(num == 0) return to_string(0);
        string result = "";
        while(num != 0){
            result = map[(num & 15)] + result; 
            num = ((unsigned)num >> 4);
        }
        return result;
    }
};
