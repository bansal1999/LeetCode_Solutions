class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for(int i =0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int result = 0;
        
        for(auto &it: mp){
            int val = it.first;
            int freq = it.second;
            
            if(k > 0 && mp.find(k + val) != mp.end()){
                result++;
            }
            else if(k == 0 && freq > 1){
                result++;
            }
        }
        return result;
    }
};