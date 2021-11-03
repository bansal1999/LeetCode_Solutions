class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        vector<int> result;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i = mp.begin(); i!= mp.end(); i++)
        {
            minHeap.push({i->second, i->first});
            
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        
        while(!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};