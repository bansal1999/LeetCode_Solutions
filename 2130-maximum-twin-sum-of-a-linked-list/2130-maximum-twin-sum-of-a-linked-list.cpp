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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = NULL, *curr = head, *nextstop;
        
        while(curr != NULL)
        {
            nextstop = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextstop;
        }
        return prev;
    }
    
    
    
    int pairSum(ListNode* head) {
        int ans = 0;
        
        ListNode* midNode = findMiddle(head);
        ListNode* head2 = reverseLL(midNode -> next);
        
        midNode -> next = NULL;
        
        ListNode* p1 = head, *p2 = head2;
        
        while(p1 != NULL && p2 != NULL)
        {
            ans = max(p1-> val + p2 -> val, ans);
            p1 = p1->next;
            p2 = p2 -> next;
        }
        
        return ans;
    }
};