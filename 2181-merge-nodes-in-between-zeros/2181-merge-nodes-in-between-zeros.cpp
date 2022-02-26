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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* zero = head;
        ListNode* ptr = head -> next;
        
        while(ptr != NULL)
        {
            if(ptr -> val != 0)
            {
                zero -> val += ptr -> val;
            }
            else
            {
               if(ptr -> next == NULL)
               {
                    zero -> next = NULL;
               }
                else
                {
                    zero -> next = ptr;
                }
                zero = ptr;
            }
            ptr = ptr -> next;
        }
        
        return head;
    }
};