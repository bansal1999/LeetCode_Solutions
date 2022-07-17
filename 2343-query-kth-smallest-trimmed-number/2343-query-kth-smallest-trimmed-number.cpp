class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        
        for(auto &it: queries){
            priority_queue<pair<string, int>> pq;
            for(int i =0; i < nums.size(); i++){
                int substrIdx = nums[i].size() - it[1];
                string subString = nums[i].substr(substrIdx, it[1]);
                
                if(pq.size() < it[0]){
                    pq.push({subString, i});
                }
                else{
                    if(pq.top().first > subString){
                        pq.pop();
                        pq.push({subString, i});
                    }
                }
            }
            int ans = pq.top().second;
            res.push_back(ans);
            
        }
        
        return res;
    }
};