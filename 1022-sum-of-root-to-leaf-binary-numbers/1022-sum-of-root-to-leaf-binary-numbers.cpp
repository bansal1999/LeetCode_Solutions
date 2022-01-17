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
    void helper(TreeNode* root, int val, int &sum)
    {
        if(!root)
            return;
        
        val = (val*2) + (root -> val);
        helper(root -> left, val, sum);
        helper(root -> right, val, sum);
        
        if(root -> left == NULL && root -> right == NULL)
        {
            sum += val;
        }
    }
    
    
    
    int sumRootToLeaf(TreeNode* root) {
        int sum =0;
        helper(root, 0, sum);
        return sum;
    }
};