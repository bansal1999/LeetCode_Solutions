class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n =arr.size();
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        
        for(int i=0; i<n; i++)
        {
            maxHeap.push({abs(arr[i] - x), arr[i]});
            
            if(maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty())
        {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};