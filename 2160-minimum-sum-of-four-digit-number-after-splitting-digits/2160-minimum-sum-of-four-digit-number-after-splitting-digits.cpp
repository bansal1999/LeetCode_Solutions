class Solution {
public:
    int minimumSum(int num) {
        int temp = num;
        vector<int> vec;
        
        while(temp != 0)
        {
            int digit = temp % 10;
            vec.push_back(digit);
            temp = temp/10;
        }
        
        sort(vec.begin(), vec.end());
        
        int new1 = vec[0]*10 + vec[3];
        int new2 = vec[1]*10 + vec[2];
        
        return new1 + new2;
    }
};