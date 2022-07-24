/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#";
        }
        
        string leftAns = serialize(root -> left);
        string rightAns = serialize(root -> right);
        
        return to_string(root -> val) + "," + leftAns + "," + rightAns;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        
        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                q.push(s);
                s = "";
                continue;
            }
            s += data[i];
        }
        
        if(s.size() != 0){
            q.push(s);
        }
        
        return helper(q);
    }
    
    TreeNode* helper(queue<string> &q){
        string node = q.front();
        q.pop();
        
        if(node == "#")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(node));
        root -> left = helper(q);
        root -> right = helper(q);
        
        return root;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));