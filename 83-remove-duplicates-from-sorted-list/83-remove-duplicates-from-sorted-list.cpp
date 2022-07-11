/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* copy;
        
        while(curr != NULL  && curr -> next != NULL){
            if(curr -> val == curr -> next -> val){
                copy = curr -> next -> next;
                if(copy == NULL){
                    curr -> next = copy;
                    break;
                }
                curr -> next = copy;
                
            }
            else{
                curr = curr -> next;
            }
        }
        return head;
    }
};