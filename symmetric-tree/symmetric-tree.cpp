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
    
    bool isSym(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL)
            return false;
        if(right -> val != left->val)
            return false;
        
        return (isSym(left->left , right->right) && isSym(left -> right, right -> left));
    }
    
    
    
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return false;
        return isSym(root->left, root->right);
        
        
   }
};