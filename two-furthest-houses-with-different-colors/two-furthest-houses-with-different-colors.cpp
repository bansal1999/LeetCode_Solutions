class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();
        int res = 0;
        int diff =0;
        for(int i=0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(colors[i] != colors[j])
                {
                     diff = abs(i-j);
                }
            }
            res = max(res, diff);
        }
        return res;
    }
};