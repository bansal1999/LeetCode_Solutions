class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> odd , even;
        vector<int> ans(n);
        
        for(int i =0; i<n; i++)
        {
            if(i%2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>()); 
        
        for(int i=0, k=0; i<n; i+=2)
        {
            ans[i] = even[k++];
        }
        
        for(int i=1, k=0; i<n; i+=2)
        {
            ans[i] = odd[k++];
        }

        return ans;

    }
};