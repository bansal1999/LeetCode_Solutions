class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)
            return true;
        
        queue<int> q;
        q.push(start);
        
        int n = arr.size();
        int vis[n];
        memset(vis, false, sizeof vis);
        vis[start] = true;
        
        while(!q.empty())
        {
            int idx = q.front();
            q.pop();
            
            if(arr[idx] == 0)
                return true;
            
            //left part 
            int left = idx - arr[idx];
            if(left >= 0 && vis[left] == false)
            {
                if(arr[left] == 0)
                    return true;
    
                vis[left] = true;
                q.push(left);
            }
            
            //right part
            int right = arr[idx] + idx;
            if(right < n && vis[right] == false)
            {
                if(arr[right] == 0)
                    return true;
                
                vis[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};