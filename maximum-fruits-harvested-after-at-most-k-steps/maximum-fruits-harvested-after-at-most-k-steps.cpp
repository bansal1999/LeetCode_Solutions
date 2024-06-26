class Solution {
private:
    bool isValid(int startPos, int k, int left, int right )
    {
        if(right <= startPos)
        {
            return (startPos - left <= k);
        }
        else if( left >= startPos)
        {
            return (right - startPos <= k);
        }
        else
        {
            int x = startPos - left;
            int y = right - startPos;
            if(2*x + y <= k || 2*y + x <= k)
                return true;
        }
        return false;
    }
    
    
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int maxi =  0;
        int left =  0;
        int right = 0;
        int sum =   0;
        int n = fruits.size();
        while(right < n)
        {
            sum += fruits[right][1];
            while(left <= right && isValid(startPos, k, fruits[left][0], fruits[right][0]) == false)
            {
                sum -= fruits[left][1];
                left++;
            }
            maxi = max(maxi, sum);
            right++;
        }
        return maxi;
    }
};