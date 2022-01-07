class Solution {
public:
    
    int getNext(int n)
    {
        int totalSum = 0;
        while(n > 0)
        {
            int d = n % 10;
            n = n/10;
            
            totalSum += d*d;
        }
        return totalSum;
    }
    
    
    
    
    
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        
        while(n != 1 && (mp.find(n) == mp.end()))
        {
            mp[n] += 1;
            n = getNext(n);
        }
        return n == 1;
        
    }
};