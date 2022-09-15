class Solution {
public:
    int arraySign(vector<int>& nums) {
        long int prod = 1;
        for(auto &it: nums){
            if(it == 0)
                return 0;
            else if( it > 0)
                it = 1;
            else
                it = -1;
            
            prod *= it;
        }
        
        if(prod > 0)
            return 1;
        else if(prod < 0)
            return -1;
        else
            return 0;
    }
};