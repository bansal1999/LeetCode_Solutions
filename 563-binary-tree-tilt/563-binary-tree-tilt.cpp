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
    int subtreeSum(TreeNode* root, int &tilt)
    {
        if(root == NULL)
            return 0;
        
        //Postorder Traversal
        int leftSum = subtreeSum(root -> left, tilt);
        int rightSum = subtreeSum(root -> right, tilt);
        
        tilt += abs(leftSum - rightSum);
        return leftSum + rightSum + root -> val;
    }
        

    int findTilt(TreeNode* root) {
        int tilt =0;
        subtreeSum(root, tilt);
        
        return tilt;
    }
};