class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int left = 0;
        int right = 0;
        int numZero = 0;
        
        while(right < nums.size()){
            
            if(nums[right] == 0){
                numZero++;
            }
            
            while(numZero == 2){
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