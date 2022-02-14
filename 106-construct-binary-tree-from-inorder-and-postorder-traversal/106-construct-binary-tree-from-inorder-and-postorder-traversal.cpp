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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        populateMap(mp, inorder);
        
        int postIndex = (postorder.size() - 1);
        
        return constructTree(inorder, postorder, mp, 0, inorder.size() - 1, postIndex);
        
    }
    
    void populateMap(unordered_map<int, int> &mp, vector<int> &inorder)
    {
        for(int i=0; i< inorder.size(); i++)
        {
            mp[inorder[i]] = i; 
        }
    }
    
    TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int start, int end, int &postIndex)
    {
        if(start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postIndex]);
        int currIndex = mp[postorder[postIndex]];
        
        postIndex -= 1;
        
        root -> right = constructTree(inorder, postorder, mp, currIndex + 1, end, postIndex);
        root -> left = constructTree(inorder, postorder, mp, start, currIndex - 1, postIndex);
        
        return root;
        
    }
    
};