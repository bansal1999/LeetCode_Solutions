class Solution {
public:
    
    void partition(vector<int>& nums, int pivot)
    {
        int n=nums.size();
        for(int i=0, j=0; i<n; i++)
        {
            if(nums[i] < pivot)
            {
                swap(nums[i], nums[j++]);
            }
        }
    }
    
    
    void sortColors(vector<int>& nums) {
        
        int pivot =1;
        partition(nums, pivot);
        
        pivot = 2;
        
        partition(nums, pivot);
        
    }
};