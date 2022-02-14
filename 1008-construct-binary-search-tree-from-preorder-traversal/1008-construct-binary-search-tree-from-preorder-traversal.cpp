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
        int preIndex[1] = {0};
        
        return buildTree(preorder, preIndex, 1001);
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preIndex[1], int maxVal)
    {
        if(preIndex[0] >= preorder.size() || preorder[preIndex[0]] >= maxVal)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex[0]]);
        preIndex[0] += 1;
        
        root -> left = buildTree(preorder, preIndex, root -> val);
        root -> right = buildTree(preorder, preIndex, maxVal);
        
        return root;
    }
};