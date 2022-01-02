class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int n = bank[0].size();
        
        int prev =0, curr =0, cnt =0;
        
        for(int i =0; i<m; i++)
        {
            curr = 0;
            for(int j =0; j<n; j ++)
            {
                if(bank[i][j] == '1')
                    curr++;
            }
            
            cnt += prev*curr;
            if(curr)
                prev = curr;
        }
        return cnt;
    }
};