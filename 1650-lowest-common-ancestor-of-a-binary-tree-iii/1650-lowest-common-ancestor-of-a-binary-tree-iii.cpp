/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> seen;
        
        while(p != NULL)
        {
            seen.insert(p);
            p = p -> parent;
        }
        
        while(q != NULL)
        {
            if(seen.find(q) != seen.end())
                return q;
            
            q = q -> parent;
        }
        
        return NULL;
        
    }
};