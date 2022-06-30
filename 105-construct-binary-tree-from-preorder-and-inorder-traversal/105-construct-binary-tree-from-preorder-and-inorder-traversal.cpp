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
    // 1st element of the preorder array is the root of the BT
    //initializse preindex to 0
    //inital range of index = (0 to n -1)
    // make a new node of value located on preorder[preindex]
    // Locate the index of the root in inorder array --> currentIndex
    // increment the  preindex of preorder array
    // attacth the left subtree of BT in the index range (0 to CI - 1)
    // attach the right subtree of BT in the range (CI + 1 to n -1)
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        populateMap(mp, inorder);
        
        int preIndex = 0;
        return constructTree(preorder, inorder, mp, 0, inorder.size() -1, preIndex);
        
    }
    
    void populateMap(unordered_map<int, int> &mp, vector<int>& inorder)
    {
        for(int i=0; i< inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return;
    }
    
    TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int start, int end, int &preIndex)
    {
        if(start > end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int currIndex = mp[preorder[preIndex]];
        
        preIndex += 1;
        
        root -> left = constructTree(preorder, inorder, mp, start, currIndex - 1, preIndex);
        root -> right = constructTree(preorder, inorder, mp, currIndex + 1, end, preIndex);
        
        return root;
    }

};