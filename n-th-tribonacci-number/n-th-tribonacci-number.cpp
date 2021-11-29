class Solution {
public:
    unordered_map<int, int> memo;
    int tribonacci(int n) {
        
        if(n == 1 || n == 0)
            return n;
        if(n==2)
            return 1;
        if(memo.find(n) != memo.end())
            return memo[n];
        memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
        return memo[n];
    }
};