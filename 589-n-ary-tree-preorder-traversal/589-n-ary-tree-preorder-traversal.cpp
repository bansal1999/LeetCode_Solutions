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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> stk;
        
        if(root == NULL)
            return ans;
        
        stk.push(root);
        
        while(!stk.empty())
        {
            Node* currNode = stk.top();
            stk.pop();
            ans.push_back(currNode -> val);
            
            vector<Node*> children = currNode -> children;
            int n = children.size();
            
            for(int i = n-1; i>= 0; i--)
            {
                stk.push(children[i]);
            }
        }
        
        return ans;
    }
};