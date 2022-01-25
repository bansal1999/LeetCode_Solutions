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
    bool isUnivalTree(TreeNode* root) {
        return check(root, root -> val);
    }
    
    
    bool check(TreeNode* root, int currVal)
    {
        if(root == NULL)
            return true;
        if(root -> val != currVal)
            return false;
        
        int leftans = check(root-> left, currVal);
        int rightans = check(root -> right, currVal);
        
        return leftans && rightans;
    }
};