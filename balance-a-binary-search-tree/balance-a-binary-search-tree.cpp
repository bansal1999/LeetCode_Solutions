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
    
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inOrderBST(root);
        return buildBST(0, sortedArr.size() -1);
    }
    
    void inOrderBST(TreeNode* root)
    {
        if(root == NULL)
            return;
        inOrderBST(root -> left);
        sortedArr.push_back(root);
        inOrderBST(root -> right);
    }
    
    TreeNode* buildBST(int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode* root = sortedArr[mid];
        root -> left = buildBST(start, mid -1);
        root -> right = buildBST(mid + 1, end);
        
        return root;
    }
};