/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        set<TreeNode*> s;
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        
        populateMap(root, NULL, parentMap);
        printkDistance(target, k, s, ans, parentMap );
        
        return ans;
    }
    
    void populateMap(TreeNode* currNode, TreeNode* currParent, unordered_map<TreeNode*, TreeNode*> &parentMap)
    {
        if(currNode == NULL)
            return;
        
        parentMap[currNode] = currParent;
        populateMap(currNode -> left, currNode, parentMap);
        populateMap(currNode -> right, currNode, parentMap);
        
        return;
    }
    
    void printkDistance(TreeNode* currNode, int k, set<TreeNode*> &s, vector<int> &ans, unordered_map<TreeNode*, TreeNode*> &parentMap)
    {
        if(currNode == NULL || s.find(currNode) != s.end() || k < 0)
            return;
        
        s.insert(currNode);
        
        if(k == 0)
        {
            ans.push_back(currNode -> val);
            return;
        }
        
        printkDistance(currNode->left, k - 1, s, ans, parentMap);
        printkDistance(currNode->right, k - 1, s, ans, parentMap);
        printkDistance(parentMap[currNode], k - 1, s, ans, parentMap);
        
        return;
    }
    
    
};

