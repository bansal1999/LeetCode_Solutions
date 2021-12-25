class Solution {
public:
    int countPoints(string rings) {
        set<int> b, g, r;
        
        int n = rings.size();
        
        for(int i=0; i<n; i += 2)
        {
            int rod = rings[i+1] - '0';
            if(rings[i] == 'G')
            {
                 g.insert(rod);
            }
            else if(rings[i] == 'B')
            {
                 b.insert(rod);
            }
            else
            {
                r.insert(rod);
            }
        }
        
        int cnt  =0;
        for(int i =0; i< 10; i++)
        {
            if(r.count(i) && b.count(i) && g.count(i))
                cnt += 1;
        }
        return cnt;
    }
};