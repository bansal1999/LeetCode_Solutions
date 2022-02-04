class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minDiff = 0 ;
        long maxDiff = 0;
        long nums =0;
        
        for(int i=0; i<differences.size(); i++ )
        {
            nums += differences[i];
            minDiff = min(minDiff, nums);
            maxDiff = max(maxDiff, nums);
        }
        
        int cnt = (upper - maxDiff) - (lower - minDiff) + 1;
        
        return max(0, cnt);
        
    }
};