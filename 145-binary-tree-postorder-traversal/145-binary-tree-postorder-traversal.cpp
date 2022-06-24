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
    //Iterative approach using 1 stack
    // Approach: just reverse the preorder traverval approach ans vector !!
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        if(root == NULL)
            return ans;
        
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode* curr = stk.top();
            stk.pop();
            ans.push_back(curr -> val);
            
            if(curr-> left != NULL)
                stk.push(curr -> left);
            
            if(curr -> right != NULL)
                stk.push(curr -> right);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};