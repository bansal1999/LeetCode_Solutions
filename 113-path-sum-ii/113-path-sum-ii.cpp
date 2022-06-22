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
    void hasPath(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &path){
        
        if(root == NULL){
            return;
        }
        
        targetSum -= root-> val;
        path.push_back(root -> val);
        
        if(targetSum == 0 && root -> left == NULL && root -> right == NULL){
            result.push_back(path);
        }else{
            hasPath(root -> left, targetSum, result, path);
            hasPath(root -> right, targetSum, result, path);
        }
        
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        
        hasPath(root, targetSum, result, path);
        
        return result;
    }
};