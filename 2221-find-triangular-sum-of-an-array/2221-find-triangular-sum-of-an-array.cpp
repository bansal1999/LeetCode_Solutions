class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, n);
    }
    
    int helper(vector<int> num, int n){
        if(n == 1){
            return num[0];
        }
        
        for(int i = 0; i < n-1; i++){
            num[i] = (num[i] + num[i+1])%10;
        }
        
        return helper(num, n-1);
    }
};
