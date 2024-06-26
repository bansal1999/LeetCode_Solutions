/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return root;
        
        if(p == root || q == root)
            return root;
        
        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root-> right, p, q);
        
        if(leftRes == NULL && rightRes == NULL)
            return NULL;
        
        if(leftRes != NULL && rightRes != NULL)
            return root;
        
        return leftRes == NULL ? rightRes : leftRes;
        
        
        
        
        
        
        
    }
};