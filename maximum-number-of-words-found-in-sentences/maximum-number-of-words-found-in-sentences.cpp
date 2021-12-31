class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxiCnt =0;
        
        for(auto &it: sentences)
        {
            int cnt  =0;
            for(auto &ch: it)
            {
                if(ch == ' ')
                    cnt++;
            }
            maxiCnt = max(maxiCnt, cnt+1);
        }
        return maxiCnt;
    }
};