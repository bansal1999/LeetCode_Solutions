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
    //Iterative approach
    vector<int> postorderTraversal(TreeNode* root)  {
        // iterative solution using 2 stacks

        stack<TreeNode*> stk1, stk2;
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        stk1.push(root);
        
        while(!stk1.empty()){
            TreeNode* node = stk1.top();
            //node = stk1.top();
            stk1.pop();
            stk2.push(node);
            
            if(node -> left != NULL){
                stk1.push(node -> left);
            }
            
            if(node -> right != NULL){
                stk1.push(node -> right);
            }
        }
        
        while(!stk2.empty()){
            ans.push_back(stk2.top() -> val);
            stk2.pop();
        }
        
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};