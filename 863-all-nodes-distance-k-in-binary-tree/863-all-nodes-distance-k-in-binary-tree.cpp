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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentStore)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode -> left)
            {
                parentStore[currNode -> left] = currNode;
                q.push(currNode -> left);
                
            }
            
            if(currNode -> right)
            {
                parentStore[currNode -> right] = currNode;
                q.push(currNode -> right) ;
            }
            
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentStore;
        markParent(root,parentStore);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qu;
        qu.push(target);
        visited[target] = true;
        int currLvl = 0;
        
        while(!qu.empty())
        {
            int sz = qu.size();
            if(currLvl == k)
                break;
            
            currLvl += 1;
            
            for(int i=0; i< sz; i++)
            {
                TreeNode* curr = qu.front();
                qu.pop();
                
                if(curr -> left && !visited[curr -> left])
                {
                    qu.push(curr -> left);
                    visited[curr -> left] = true;
                }
                
                if(curr -> right && !visited[curr -> right])
                {
                    qu.push(curr -> right);
                    visited[curr -> right]  = true;
                }
                
                if(parentStore[curr] && !visited[parentStore[curr]])
                {
                    qu.push(parentStore[curr]);
                    visited[parentStore[curr]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!qu.empty())
        {
            TreeNode* current = qu.front();
            qu.pop();
            
            res.push_back(current -> val);
        }
        return res;
        
    }
};