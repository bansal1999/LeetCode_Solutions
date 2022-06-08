class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long prefixSum = 0;
        int longestLength = 0;
        unordered_map<int, int> mp;
        
        for(int i =0; i <nums.size(); i++){
            prefixSum += nums[i];
            
            if(prefixSum == k){
                longestLength = i+1;
            }
            
            if(mp.find(prefixSum - k) != mp.end()){
                longestLength = max(longestLength , i-mp[prefixSum - k]);
            }
            
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }
        }
        return longestLength;
        
    }
};