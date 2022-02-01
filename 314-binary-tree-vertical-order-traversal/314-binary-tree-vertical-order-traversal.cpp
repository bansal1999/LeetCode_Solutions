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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(root == NULL)
            return output;
        
        map<int, vector<int>> mp;
        queue<pair<int, TreeNode*>> q;
        
        q.push({0, root});
        
        while(!q.empty())
        {
            TreeNode* currNode = q.front().second;
            int col = q.front().first;
            q.pop();
            
            mp[col].push_back(currNode->val);
            
            if(currNode->left)
            {
                q.push({col -1, currNode -> left});
            }
            
            if(currNode->right)
            {
                q.push({col + 1, currNode -> right});
            }
            
        }
        
        for(auto &it: mp)
        {
            output.push_back(it.second);
        }
        
        return output;
    }
};