class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i =0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                twoSumII(nums, i, ans);
            }
        }
        return ans;
    }
    
    void twoSumII(vector<int>& nums, int i, vector<vector<int>> &ans){
        unordered_set<int> st;
        
        for(int j = i +1; j < nums.size(); j++){
            int comp = -nums[i] - nums[j];
            if(st.find(comp) != st.end()){
                ans.push_back({nums[i] , comp, nums[j]});
                while(j + 1 < nums.size() && nums[j] == nums[j +1]){
                    j++;
                }
            }
            st.insert(nums[j]);
        }
    }
    
//     void twoSumII(vector<int>& nums, int i, vector<vector<int>> &ans){
//         int lo = i + 1, hi = nums.size() - 1;
        
//         while(lo < hi){
//             int sum = nums[i] + nums[lo] + nums[hi];
            
//             if(sum < 0){
//                 lo++;
//             }
//             else if(sum > 0){
//                 hi--;
//             }
//             else{
//                 ans.push_back({nums[i], nums[lo++], nums[hi--]});
//                 while(lo < hi && nums[lo] == nums[lo -1]){
//                     ++lo;
//                 }
//             }
//         }
//     }
    
};