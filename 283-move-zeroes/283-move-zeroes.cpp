class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonzero = 0;
        
        for(int curr = 0; curr < nums.size(); curr++){
            if(nums[curr] != 0){
                nums[lastNonzero] = nums[curr];
                lastNonzero++;
            }
        }
        
        for(int i = lastNonzero; i < nums.size(); i++){
            nums[i] = 0;
        }
        
    }
};