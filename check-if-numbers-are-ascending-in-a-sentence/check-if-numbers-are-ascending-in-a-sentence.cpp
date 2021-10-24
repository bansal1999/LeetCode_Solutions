class Solution {
public:
    bool areNumbersAscending(string s) {
        
        vector<int> nums;
        int n = s.size();
        
        for(int i=0; i< n; i++)
        {
            if(isdigit(s[i]))
            {
                string temp;
                while(i < n && isdigit(s[i]))
                    temp += s[i++];
                
                nums.push_back(stoi(temp));
            }
        }
        
        for(int i=0; i< nums.size()-1; i++)
        {
            if(nums[i] >= nums[i+1])
                return false;
                
        }
        
        return true;
        
        
        
    }
};