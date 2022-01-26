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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        rootLeafpath(root, "", ans);
        return ans;
    }
    
    void rootLeafpath(TreeNode* root, string currPath, vector<string>&ans)
    {
        if(root == NULL)
            return;
        
        if(root-> left == NULL && root -> right ==NULL)
        {
            currPath += to_string(root-> val);
            ans.push_back(currPath);
            return;
            
        }
        
        currPath += to_string(root->val) + "->";
        rootLeafpath(root -> left, currPath, ans);
        rootLeafpath(root -> right, currPath, ans);
        return;
        
    }
};