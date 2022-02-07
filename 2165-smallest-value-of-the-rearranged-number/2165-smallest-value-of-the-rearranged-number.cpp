class Solution {
public:
    long long smallestNumber(long long num) {
        string str = to_string(abs(num));
        
        if(num >= 0)
            sort(str.begin(), str.end());
        else
            sort(str.begin(), str.end(), greater<char>());
        
        if(num > 0)
        {
            int idx = str.find_first_not_of('0');
            swap(str[0], str[idx]);
        }
        
        long long int ans = stoll(str);
        
        if(num < 0)
            ans *= -1;
        
        return ans;
        
    }
};