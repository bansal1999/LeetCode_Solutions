class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int x = INT_MAX, ans;
        
        for(int i=0; i < nums.size(); i++)
        {
            if(abs(nums[i]) < x)
            {
                x = abs(nums[i]);
                ans = nums[i];
            }
            else if(abs(nums[i]) == x)
            {
                ans = max(nums[i], ans);
            }
        }
        return ans;
    }
};