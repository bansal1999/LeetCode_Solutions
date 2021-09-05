class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        left[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1]+ nums[i];
        }
        
        right[n-1]=nums[n-1];
        for(int j=(n-2); j>=0; j--)
        {
            right[j] = nums[j]+right[j+1];
        }
        
        for(int k=0; k<n; k++)
        {
            if(left[k]==right[k])
                return k;
        }
        
        return -1;
    }
};