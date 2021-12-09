class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cntD(10, 0);
        for(int  i = 0; i< digits.size(); i++)
        {
            cntD[digits[i]]++;
        }
        
        vector<int> res;
        
        for(int num = 100; num<999; num+=2)
        {
            vector<int> countCurr(10, 0);
            int temp = num;
            while(temp)
            {
                countCurr[temp % 10]++;
                temp /= 10;
            }
            
            bool flag = true;
            for(int i =0; i< 10; i++)
            {
                if(countCurr[i] > cntD[i])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                res.push_back(num);
            }
        }
        
        return res;
        
    }
};