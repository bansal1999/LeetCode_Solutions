class Solution {
public:
    vector<int> NSR(vector<int> &heights)
    {
        vector<int> right;
        stack<pair<int, int>> stk;
        
        for(int i = heights.size() - 1; i>=0; i--)
        {
            if(stk.empty())
                right.push_back(heights.size());
            else if(!stk.empty() && stk.top().first < heights[i])
                right.push_back(stk.top().second);
            else if(!stk.empty() && stk.top().first >= heights[i])
            {
                while(!stk.empty() && stk.top().first >= heights[i])
                {
                    stk.pop();
                }
                if(stk.empty())
                    right.push_back(heights.size());
                else
                    right.push_back(stk.top().second);
            }
            stk.push({heights[i], i});
        }
        
        reverse(right.begin(), right.end());
        return right;
        
    }
    
    vector<int> NSL(vector<int> heights)
    {
        vector<int> left;
        stack<pair<int, int>> stk;
        
        for(int i =0; i< heights.size(); i++)
        {
            if(stk.empty())
                left.push_back(-1);
            else if(!stk.empty() && stk.top().first < heights[i])
                left.push_back(stk.top().second);
            else if(!stk.empty() && stk.top().first >= heights[i])
            {
                while(!stk.empty() && stk.top().first >= heights[i])
                {
                    stk.pop();
                }
                if(stk.empty())
                    left.push_back(-1);
                else
                    left.push_back(stk.top().second);
            }
            stk.push({heights[i], i});
        }
        return left;
    }
    
    
    int MAH(vector<int> &heights)
    {
        vector<int> right;
        vector<int> left;
        
        right = NSR(heights);
        left = NSL(heights);
        
        vector<int> width;
        int mx =0;
        
        for(int i =0; i< left.size(); i++)
        {
            width.push_back(right[i] - left[i] - 1);
        }
        
        for(int i =0; i< heights.size(); i++)
        {
            mx = max(mx, width[i]*heights[i]);
        }
        
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> v;
        
        for(int j =0; j< m; j++)
        {
            v.push_back(matrix[0][j] - '0');
        }
        
        int mx = MAH(v);
        
        for(int i =1; i< n; i++)
        {
            for(int j =0; j< m; j++)
            {
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] = v[j] + (matrix[i][j] - '0');
            }
            
            mx = max(mx, MAH(v));
            
        }
        return mx;
    }
};