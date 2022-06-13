class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left =0, right = 0;
        int maxCnt = 0, numZero = 0 ;
        
        while(right < nums.size()){
            if(nums[right] == 0){
                numZero++;
            }
            
            while(numZero == k + 1){
                if(nums[left] == 0){
                    numZero--;
                }
                left++;
            }
            
            maxCnt = max(maxCnt, right - left + 1);
            right++;
        }
        return maxCnt;
    }
};