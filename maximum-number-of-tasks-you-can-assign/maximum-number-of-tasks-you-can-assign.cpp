class Solution {
private:
    bool isValid(vector<int>&tasks, vector<int>& workers, const int &maxT, int pills, int strength)
    {
        multiset<int> workerMs(workers.end() - maxT, workers.end());
        
        
        for(int i = maxT - 1; i>=0; i--)
        {
            auto it = workerMs.lower_bound(tasks[i]);
            if(it == workerMs.end())
            {
                pills -= 1;
                it = workerMs.lower_bound(tasks[i] - strength);
            }
            if(it == workerMs.end() || pills < 0)
                return false;
            
            workerMs.erase(it);
        }
        return true;
    }
        
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int ts = tasks.size();
        int ws = workers.size();
        
        int low = 0;
        int high = min(ts, ws);
        
        while(low != high)
        {
            int mid = (low +high +1)/2;
            if(isValid(tasks, workers, mid, pills, strength))
            {
                low = mid;
            }
            else
            {
                high = mid -1;
            }
        }
        return high;
        
    }
};