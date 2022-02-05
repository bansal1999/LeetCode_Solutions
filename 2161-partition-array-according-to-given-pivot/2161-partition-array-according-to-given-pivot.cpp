class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> more;
        vector<int> equal;
        
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i] < pivot)
                less.push_back(nums[i]);
            else if (nums[i] > pivot)
                more.push_back(nums[i]);
            else
                equal.push_back(nums[i]);
        }
        
        vector<int> ans;
        
        for(int i=0; i< less.size(); i++)
        {
            ans.push_back(less[i]);
        }
        
       for(int i=0; i< equal.size(); i++)
        {
            ans.push_back(equal[i]);
        }
        
        
        for(int i=0; i< more.size(); i++)
        {
            ans.push_back(more[i]);
        }
        
        return ans;
    }
};