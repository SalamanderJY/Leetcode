class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if (countOnes(h) + countOnes(m) == num) {
                    times.push_back(to_string(h) +  (m < 10 ?  ":0" : ":") + to_string(m));
                }
        return times; 
    }
    
    int countOnes(int num) {
        int count = 0;
        while (num != 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }
};
