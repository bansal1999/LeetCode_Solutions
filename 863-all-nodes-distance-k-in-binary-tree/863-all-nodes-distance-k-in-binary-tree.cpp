/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Self Notes:
// \U0001f34b Mark each node to its parent to traverse upwards
// \U0001f34b We will do a BFS traversal starting from the target node
// \U0001f34b As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
// \U0001f34b when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result

class Solution {
public:
    void markParents(unordered_map<TreeNode*, TreeNode*> &parentMap, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr -> left){
                parentMap[curr -> left] = curr;
                q.push(curr -> left);
            }
            
            if(curr -> right){
                parentMap[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;  // node -> parent
        markParents(parentMap, root);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        visited[target] = true;
        q.push(target);
        
        int currLevel = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            if(currLevel == k){
                break;
            }
            currLevel++;
            
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left && !visited[curr -> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                
                if(curr -> right && !visited[curr -> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                
                if(parentMap[curr] && !visited[parentMap[curr]]){
                    q.push(parentMap[curr]);
                    visited[parentMap[curr]] = true;
                }
                
            }
            
        }
        
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr -> val);
        }
        return result;
    }
};