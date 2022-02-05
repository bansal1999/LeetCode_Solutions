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
        vector<int> inorder;
        inorderTravel(root, inorder);
        
        for(int i=1; i< inorder.size(); i++)
        {
            if(inorder[i-1] >= inorder[i])
                return false;
        }
        return true;
    }
    
    void inorderTravel(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
            return;
        
        inorderTravel(root-> left, inorder);
        inorder.push_back(root->val);
        inorderTravel(root-> right, inorder);
    }
};