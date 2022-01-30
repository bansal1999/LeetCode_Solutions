/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        
        if(root == NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty())
        {
            int currSize = q.size();
            vector<int> level;
            
            while(currSize > 0)
            {
                Node* currNode = q.front();
                q.pop();
                
                level.push_back(currNode -> val );
                currSize--;
                
               
                for(auto child: currNode->children)
                {
                    q.push(child);
                }
                
            }
            
            ans.push_back(level);
        }
        return ans;
    }
};