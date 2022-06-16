class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int, int>>> maxHeap;
        
        for(int i =0; i < nums1.size(); i++){
            for(int j =0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                if(maxHeap.size() < k){
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }
                else if(sum < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            auto ele = maxHeap.top();
            maxHeap.pop();

            ans.push_back({ele.second.first, ele.second.second});
        }
        
        return ans; 
    }
};