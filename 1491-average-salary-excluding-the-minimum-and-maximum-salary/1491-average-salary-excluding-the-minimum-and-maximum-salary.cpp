class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0;
        int maxi = INT_MIN, mini = INT_MAX;
        for(auto &it: salary){
            sum += it;
            maxi = max(maxi, it);
            mini = min(mini, it);
        }
        int n = salary.size();
        double avg = (sum - mini - maxi);
        avg = (avg)/(n-2);
        
        return avg;
        
    }
};