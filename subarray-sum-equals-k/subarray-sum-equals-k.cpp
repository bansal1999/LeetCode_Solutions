class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //history of prefix sums
        unordered_map<int, int> m;
        int n = nums.size(), res =0, i, total=0;
        
        m[0] =1;
        
        for(int i=0; i< n; i++)
        {
            total += nums[i];
            res += m[total - k];
            
            m[total]++;
        }
        
        return res;
    }
};