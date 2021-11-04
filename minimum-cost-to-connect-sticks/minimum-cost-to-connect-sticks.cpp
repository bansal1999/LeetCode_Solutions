class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0; i < sticks.size(); i++)
        {
            minHeap.push(sticks[i]);
        }
        
        int total =0;
        while(minHeap.size() >= 2 )
        {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            
            total = first + second + total;
            minHeap.push(first + second);
            
        }
        
//         int top1 = minHeap.top();
//         minHeap.pop();
//         int top2 = minHeap.top();
//         minHeap.pop();
        
//         return (top1 + top2);
        return total;
        
    }
};