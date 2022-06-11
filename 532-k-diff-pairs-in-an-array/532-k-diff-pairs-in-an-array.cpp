class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1;
        int ans =0;
        
        while(left < nums.size() && right < nums.size()){
            if(left == right || nums[right] - nums[left] < k){
                right++;
            }
            else if (nums[right] - nums[left] > k){
                left++;
            }
            else{
                left++;
                right++;
                ans++;
                
                while(left < nums.size() && nums[left] == nums[left -1]){
                    left++;
                }
            }
        }
        return ans;
    }
};