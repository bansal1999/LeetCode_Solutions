/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> output;
        q.push(root);
        
        int level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> vec(size);
            for(int i =0; i< size; i++)
            {
                TreeNode* currNode = q.front();
                 q.pop();
            
                if(level == 0)
                {
                    vec[i] = (currNode -> val);
                }
                else
                {
                    vec[size - i - 1] = currNode -> val;
                }
                
                if(currNode -> left)
                    q.push(currNode -> left);
                if(currNode -> right)
                    q.push(currNode -> right);
                
            }
            output.push_back(vec);
            level = !level;
            
                
        }
        return output;
        
    }
};