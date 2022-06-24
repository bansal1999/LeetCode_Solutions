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
    // approach: at every step calculate the left and right hight of the tree
    // diameter is the maximum of (leftheight + rightHeight) where height is standard algorithm
    
    int helper(TreeNode* node, int &diameter)
    {
        if(node == NULL)
            return 0;
        int lh = helper(node -> left, diameter);
        int rh = helper(node -> right, diameter);
        
        diameter = max(diameter, lh + rh);
        return 1+max(rh, lh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter =0;
        helper(root, diameter);
        return diameter;
    }
    
    
};