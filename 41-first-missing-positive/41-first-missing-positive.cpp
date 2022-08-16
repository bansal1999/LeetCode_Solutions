class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> memo;
        for(int i : nums) memo[i]++;
        
        int res = 1;
        while(true){
            if(memo.count(res)) res++;
            else break;
        }
        
        return res;
    }
};