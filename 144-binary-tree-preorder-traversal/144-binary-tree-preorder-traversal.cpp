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
    // Interative approach
    // call on the right subtree then left subtree to access the elements of Left first in LIFO manner
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> preorder;
        
        if(root == NULL)
            return ans;
        
        preorder.push(root);
        
        while(!preorder.empty())
        {
            TreeNode* curr = preorder.top();
            preorder.pop();
            ans.push_back(curr -> val);
            
            if(curr -> right != NULL)
                preorder.push(curr -> right);
            
            if(curr -> left != NULL)
                preorder.push(curr -> left);
        }
        return ans;
    }
};