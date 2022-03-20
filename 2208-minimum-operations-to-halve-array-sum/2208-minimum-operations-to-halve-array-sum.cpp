class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double totalSum = 0;
        double requiredSum = 0;
        
        for(auto &it: nums)
        {
            totalSum += it;
            pq.push(it);
        }
        
        requiredSum = totalSum/2;
        int minOps = 0;
        
        while(totalSum > requiredSum)
        {
            double currTop = pq.top();
            pq.pop();
            currTop = currTop/2;
            
            totalSum -= currTop;
            pq.push(currTop);
            minOps++;
        }
        
        return minOps;
    }
};