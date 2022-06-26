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
        unordered_map<TreeNode*, TreeNode*> parentMap;
        set<TreeNode*> visited;
        vector<int> ans;
        
        populateMap(parentMap, root, NULL);
        printDistancek(target, k, parentMap, visited, ans);
        
        return ans;
    }
    
    void populateMap(unordered_map<TreeNode*, TreeNode*> &parentMap, TreeNode* currNode, TreeNode* currParent){
        if(currNode == NULL){
            return;
        }
        
        parentMap[currNode] = currParent;
        populateMap(parentMap, currNode -> left, currNode);
        populateMap(parentMap, currNode -> right, currNode);
        
        return;
    }
    
    void printDistancek(TreeNode* currNode, int k,  unordered_map<TreeNode*, TreeNode*> &parentMap, set<TreeNode*> &visited, vector<int> &ans){
        
        if(currNode == NULL || visited.find(currNode) != visited.end() || k < 0){
            return;
        }
        
        visited.insert(currNode);
        
        if(k == 0){
            ans.push_back(currNode -> val);
            return;
        }
        
        printDistancek(currNode -> left, k -1, parentMap, visited, ans);
        printDistancek(currNode -> right, k -1, parentMap, visited, ans);
        printDistancek(parentMap[currNode], k-1, parentMap, visited, ans);
        
        return;
        
    }
    
    
    
    
};