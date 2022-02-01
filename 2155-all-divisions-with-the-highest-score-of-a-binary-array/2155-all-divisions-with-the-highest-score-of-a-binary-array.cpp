class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int rightOnes = accumulate(nums.begin() , nums.end(), 0);
        int leftZeros = 0, maxSum = 0, currSum =0;
        
        vector<int> res;
        for(int i=0; i<= nums.size(); i++)
        {
            currSum = leftZeros + rightOnes;
            if(currSum > maxSum)
            {
                res.clear();
                maxSum = currSum;
                res.push_back(i);
            }
            else if(currSum == maxSum)
            {
                res.push_back(i);
            }
            
            if(i != nums.size())
            {
                if(nums[i] == 0)
                    leftZeros++;
                if(nums[i] == 1)
                    rightOnes--;
            }
        }
        
        return res;
    }
};