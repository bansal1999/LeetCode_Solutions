class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            currSum= max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};