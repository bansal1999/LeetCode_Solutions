class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<long long> degree(n, 0);
        for(auto &it: roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
        }
        
        sort(degree.rbegin(), degree.rend());
        long long cnt = 0;
        
        for(auto &a: degree)
        {
            cnt = cnt + a*(n--);
        }

        return cnt;
        
    }
};