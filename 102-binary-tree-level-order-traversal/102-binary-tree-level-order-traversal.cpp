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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root ==  NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int currSize = q.size();
            while(currSize > 0)
            {
                TreeNode* currNode = q.front();
                q.pop();
                
                level.push_back(currNode -> val);
                currSize--;
                
                if(currNode -> left != NULL)
                    q.push(currNode -> left);
                
                if(currNode -> right != NULL)
                    q.push(currNode -> right);
            }
            ans.push_back(level);
            
        }
        
        return ans;
    }
};