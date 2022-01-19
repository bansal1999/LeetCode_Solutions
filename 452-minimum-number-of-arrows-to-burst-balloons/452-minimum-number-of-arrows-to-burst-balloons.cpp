class Solution {
    
private:
    static bool comp(vector<int> &p1, vector<int> &p2)
    {
        if(p1[1] < p2[1])
            return true;
        return false;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int cnt = 1;
        int arrow = points[0][1];
        int n = points.size();
        
        for(int i=1; i< n; i++)
        {
            if(points[i][0] > arrow)
            {
                cnt++;
                arrow = points[i][1];
            }
        }
        
        return cnt;
        
    }
};