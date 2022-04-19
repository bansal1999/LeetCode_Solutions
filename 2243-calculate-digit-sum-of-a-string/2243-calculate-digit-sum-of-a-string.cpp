class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k)
        {
            int sum =0;
            string ans = "";
            int cnt = 0;
            
            for(int i =0; i < s.size(); i++)
            {
                sum += (s[i] - '0');
                cnt++;
                
                if(cnt == k)
                {
                    ans += to_string(sum);
                    cnt =0;
                    sum =0;
                }
            }
            
            if(cnt > 0)
                ans += to_string(sum);
            
            s = ans;
        }
        return s;
    }
};