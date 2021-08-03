class Solution {
public:
    vector<vector<int>> res;
    
    void f(vector<int>& nums, int start, int end, vector<int>& contri) {
        // Base case.
        // Empty suffix subarray.
        if (start > end) {
            res.push_back(contri);
            return;
        }
        
        // Recursive case.
        int i;
        for (i = start; i <= end && nums[i] == nums[start]; i++);
        
        int j = i;
        // 0 times.
        f(nums, j, end, contri);
        
        // 1 or more times.
        for (i = start; i < j; i++) {
            contri.push_back(nums[i]);
            f(nums, j, end, contri);
        }
        
        for (i = start; i < j; i++)
            contri.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> contri;
        f(nums, 0, nums.size()-1, contri);
        
        return res;
    }
};