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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        
        int left =0;
        int right = inorder.size() - 1;
        
        while(left < right)
        {
            if(inorder[left] + inorder[right] == k)
                return true;
            else if(inorder[left] + inorder[right] > k)
                right--;
            else
                left++;
        }
        
        return false;
    }
    
    void inorderTraversal(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
            return;
        
        inorderTraversal(root -> left, ans);
        ans.push_back(root -> val);
        inorderTraversal(root -> right, ans);
        
        return;
    }
};