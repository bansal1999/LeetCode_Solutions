class Solution {
    
private:
    vector<int> nextSmallerLeft(vector<int> &heights, int n){
        stack<int> nslStk;
        vector<int> ans(n);
        
        nslStk.push(-1);
        
        for(int i =0; i<n; i++){
            int curr = heights[i];
            while(nslStk.top() != -1 && heights[nslStk.top()] >= curr){
                nslStk.pop();
            }
            ans[i] = nslStk.top();
            nslStk.push(i);
        }
        
        return ans;
    }
    
    
    vector<int> nextSmallerRight(vector<int> &heights, int n){
        stack<int> nsrStk;
        vector<int> ans(n);
        
        nsrStk.push(-1);
        
        for(int i = n - 1; i >= 0; i--){
            int curr = heights[i];
            
            while(nsrStk.top() != -1 && heights[nsrStk.top()] >= curr){
                nsrStk.pop();
            }
            
            ans[i] = nsrStk.top();
            nsrStk.push(i);
        }
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> nsl(n);
        nsl = nextSmallerLeft(heights, n);
        
        vector<int> nsr(n);
        nsr = nextSmallerRight(heights, n);
        
        vector<int> width;
        
        int area = INT_MIN;
        
        for(int i =0; i < n; i++){
            int length = heights[i];
            
            if(nsr[i] == -1){
                nsr[i] = n;
            }
            
            int breadth = nsr[i] - nsl[i] - 1;
            int maxArea = breadth*length;
            
            area = max(maxArea, area);
        }
        return area;
    }
};