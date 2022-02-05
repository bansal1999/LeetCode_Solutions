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
    bool isValidBST(TreeNode* root) {
        long prev [1] = {-99999999999};
        
        return helper(root, prev);
    }
    
    bool helper(TreeNode* root, long prev [1])
    {
        if(root == NULL)
            return true;
        
        bool leftans = helper(root -> left, prev);
        
        if(root -> val <= prev[0])
            return false;
        
        prev[0] = root->val;
        bool rightans = helper(root -> right, prev);
            
        return leftans && rightans;
        
        
    }
};