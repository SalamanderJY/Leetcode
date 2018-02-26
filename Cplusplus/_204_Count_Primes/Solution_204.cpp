class Solution {
public:
    int countPrimes(int n) {
        // Sieve of Eeatosthese
        bool *remove = new bool[n];
        remove[2] = false;
        for (int i = 3; i < n; i++)
            if(i % 2 == 0)
               remove[i] = true;
            else
                remove[i] = false;

        for(int i = 3; i < n; i += 2)
            if(!remove[i])
            {
                if(i * i > n)  break;
                for(int j = 2; i * j < n; j++)
                    remove[i * j] = true;
            }

        int count = 0;
        for(int i = 2; i < n; i++)
            if(!remove[i])
                count++;

        delete[] remove;
        return count;
    }
};