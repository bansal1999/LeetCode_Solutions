class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i= 1; i<n; i++)
        {
            left[i] = max(left[i-1], nums[i]);
        }
        
        for(int j= n-2; j>=0; j--)
        {
            right[j] = min(right[j+1], nums[j]);
        }
        
        int count =0;
        
        for(int k = 1; k<n-1; k++)
        {
            if(nums[k] > left[k-1] && nums[k] < right[k+1])
            {
                count += 2;
            }
            else if(nums[k-1] < nums[k] && nums[k] < nums[k+1])
            {
                count += 1;
            }
            
        }
        
        return count;
    }
};