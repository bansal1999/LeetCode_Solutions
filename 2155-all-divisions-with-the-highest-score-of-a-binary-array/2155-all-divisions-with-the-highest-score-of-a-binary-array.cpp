class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> preSum(n + 1, 0);
        
        vector<int> res;
        for(int i =1; i< n+ 1; ++i)
        {
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        
        long long maxScore = -1, leftZeros =0, rightOnes = 0, currScore = 0;
        
        for(int i =0; i< n +1; ++i)
        {
            leftZeros = i - preSum[i];
            rightOnes = preSum[n] - preSum[i];
            currScore = leftZeros + rightOnes;
            
            if(currScore > maxScore)
            {
                res.clear();
                maxScore = currScore;
                
            }
            if(currScore == maxScore)
                res.push_back(i);
        }
        
        return res;
    }
};