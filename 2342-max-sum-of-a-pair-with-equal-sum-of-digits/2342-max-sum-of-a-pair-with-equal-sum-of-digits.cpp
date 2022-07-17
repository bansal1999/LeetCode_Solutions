class Solution {
public:
    int getDigitSum(int num){
        int digitsum= 0;
        
        while(num){
            digitsum += num % 10;
            num = num/10;
        }
        
        return digitsum;
    }
    
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, vector<int>> mp;
        
        for(int i =0; i < nums.size(); i++){
            int temp = nums[i];
            int digitSum = getDigitSum(temp);
            
            mp[digitSum].push_back(temp);
            
        }
        
        int ans = -1;
        for(auto &it: mp){
            if(it.second.size() > 1){
                int k = it.second.size();
                ans = max(ans, it.second[k-1] + it.second[k -2]);
            }
        }
        return ans;
        
    }
};