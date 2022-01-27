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
    
 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        if(root == NULL)
            return ans;
        addLeftSubtree(root, stk);
        
        while(!stk.empty())
        {
            TreeNode* curr = stk.top();
            stk.pop();
            ans.push_back(curr -> val);
            
            if(curr -> right != NULL)
                addLeftSubtree(curr->right, stk);
            
        }
        return ans;
    }
    
    void addLeftSubtree(TreeNode* curr, stack<TreeNode*> &stk)
    {
        stk.push(curr);
        while(curr -> left != NULL)
        {
            stk.push(curr -> left);
            curr = curr -> left;
        }
        return;
       
    }
};