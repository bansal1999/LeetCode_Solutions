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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans =0;
        
        if(root != NULL)
        {
             if(root -> val >= low && root -> val <= high)
            ans += root -> val;

            if(low < root -> val )
                ans += rangeSumBST(root -> left, low, high);

            if(high > root -> val)
                ans += rangeSumBST(root -> right, low, high);
        }
        
       
        
        return ans;
        
            
    }
};