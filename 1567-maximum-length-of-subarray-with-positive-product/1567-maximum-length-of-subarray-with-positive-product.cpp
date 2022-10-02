class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posi  = 0, nega = 0;
        int ans = INT_MIN;
        
        for(auto &it: nums){
            if(it == 0){
                posi = 0;
                nega = 0;
            }
            else if(it > 0){
                posi += 1;
                nega = nega == 0 ? 0 : nega + 1;
            }
            else{
                int temp = posi;
                posi = nega == 0 ? 0 : nega + 1;
                nega = temp + 1;
            }
            
            ans= max(ans, posi);
        }
        
        return ans;
    }
};