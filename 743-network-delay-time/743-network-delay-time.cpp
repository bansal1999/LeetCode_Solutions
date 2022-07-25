class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n+1);
        
        for(auto it: times)
        {
            int frNode = it[0];
            int toNode = it[1];
            int cost = it[2];
            
            graph[frNode].push_back({cost, toNode});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        
        pq.push({0, k});
        dist[k] = 0;
        
        
        while(!pq.empty())
        {
            auto top = pq.top();
            int currCost = top.first;
            int currNode = top.second;
            pq.pop();
            
            for(auto it: graph[currNode])
            {
                int nextNode = it.second;
                int nextDist = it.first;
                
                if(dist[nextNode] > dist[currNode] + nextDist)
                {
                    dist[nextNode] = dist[currNode] + nextDist;
                    pq.push({nextDist, nextNode});
                }
                
            }
        }
        
        int maxTime = INT_MIN;
        for(int i =1; i<= n; i++)
        {
            maxTime = max(maxTime, dist[i]);
        }
         
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};