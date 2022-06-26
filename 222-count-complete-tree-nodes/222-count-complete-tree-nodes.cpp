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

// Self Notes:
// \U0001f347 Formula is (2^TreeLevel - 1). Only works for perfect tree.
// \U0001f347 To determine if its a perfect tree, go all the way down and count the nodes on left and right side, If they match, its a perfect tree and our formula applies.
// \U0001f347 If its not a perfect tree, we go on left and right subtree and again determine if they are perfect tree.
// \U0001f347 When we have our left and right heights, we do (1 + left + right)
// \U0001f347 If we reach null, return 0
// \U0001f347 C++ note: 1 << n is the same as raising 2 to the power n, or 2^n
// Time complexiity: O(logn)^2;

class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        if(leftHeight == rightHeight){
            return (1 << leftHeight) -1;        // (2^n - 1) 
        }
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
        
    }
    
    int findLeftHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node -> left;
        }
        
        return height;
    }
    
    int findRightHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node -> right;
        }
        
        return height;
    }
    
    
    
};