class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int len=0,cur=0;
        int maxEle = *max_element(nums.begin(),nums.end());
        
        
        for(int &it:nums){
            // check for condition
            if(it==maxEle)
                cur++;
            else {
                len = max(len,cur);
                cur=0;
            }
        }
        // calculate the maximum
        len = max(cur,len);
        
        // return the maxLen
        return len;
    }
};