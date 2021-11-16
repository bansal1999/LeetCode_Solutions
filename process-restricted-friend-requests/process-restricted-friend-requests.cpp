class DSU {
    private: vector<int> parent, size;
    public: DSU(int n)
    {
        for(int i=0; i<n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    public: int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node]= findParent(parent[node]);
    }
    
    public: void unionFind(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        
        if(pv == pu)
            return;
        
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        DSU dsu(n);
        vector<bool> ans;
        for(auto it : requests)
        {
            int pu = dsu.findParent(it[0]);
            int pv = dsu.findParent(it[1]);
            
            bool fl = true;
            if(pu != pv)
            {
                for(auto &it2: restrictions)
                {
                    int pu1 = dsu.findParent(it2[0]);
                    int pv1 = dsu.findParent(it2[1]);
                    
                    if((pu1 == pu && pv1 == pv) || (pu1 == pv && pv1 == pu))
                    {
                        fl = false;
                        break;
                    }
                }
                if(fl)
                    dsu.unionFind(it[0], it[1]);
            }
              ans.push_back(fl);
        }
        
        return ans;
      
        
    }
};