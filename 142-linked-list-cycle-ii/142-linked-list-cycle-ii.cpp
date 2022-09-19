/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    
        map<ListNode*, int> st;
        
        ListNode* curr = head;
        
        while(curr != NULL){
            if(st.find(curr) != st.end()){
                return curr;
            }
             st[curr] += 1;
             curr = curr -> next;
        }
        
        return NULL;
                                                                    
    }
};