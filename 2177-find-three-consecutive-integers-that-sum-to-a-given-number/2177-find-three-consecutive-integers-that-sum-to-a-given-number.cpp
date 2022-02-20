class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // vector<long long> ans(3);
        
        if(num % 3 == 0)
        {
            long long x = num/3;
            long long x1 = x-1;
            long long x2 = x + 1;
            
            return {x1, x, x2};
        }
        else
            return {};
    }
};