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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        //empty list
        if(head == NULL)
            return NULL;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        // travel till the left 
        
        while(left > 1)
        {
            
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* tail = curr;
        ListNode* con = prev;
        
        // reverse the list from left to right
        ListNode* forward = NULL;
        while(right > 0)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            right--;
        }
        
        if(con!= NULL)
        {
            con->next = prev;
        }
        else
        {
            head = prev;
        }
        
        tail->next = curr;
        return head;
    }
};