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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx =0;
        int maxVal = 1000;
        int minVal = 1;
        
        return helper(preorder, idx, maxVal, minVal);
    }
    
    TreeNode* helper(vector<int> &preorder, int &idx, int &maxVal, int &minVal)
    {
        if(idx == preorder.size())
            return NULL;
        
        int value = preorder[idx];
        
        if(value < minVal || value > maxVal)
            return NULL;
        
        idx++;
        
        TreeNode* root = new TreeNode(value);
        root -> left = helper(preorder, idx, value, minVal);
        root -> right = helper(preorder, idx, maxVal, value);
        
        return root;
    }
};