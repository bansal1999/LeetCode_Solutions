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

    void reorderList(ListNode* head) {

        // Find the middle.

        ListNode *slow = head, *fast = head;

        while(fast && fast->next) {

            slow = slow->next;

            fast = fast->next->next;

        }

        

        // Reverse the second half.

        ListNode *second_half = slow;

        ListNode *reversed_list = NULL;

        

        while(second_half) {

            // Insert elements to the front.

            ListNode *temp = second_half->next;

            second_half->next = reversed_list;

            reversed_list = second_half;

            second_half = temp;

        }

        

        // Combine the two lists alternately.

        ListNode *first = head;

        ListNode *second = reversed_list;

        ListNode *output_head, *output_tail;

        ListNode dummy;

        output_head = output_tail = &dummy;

        

        while(second && first != second) {

            // Take one from the first list.

            output_tail->next = first;

            ListNode *temp = first->next;

            first->next = NULL;

            first = temp;

            output_tail = output_tail->next;

            

            // Take one from the second list.

            output_tail->next = second;

            temp = second->next;

            second->next = NULL;

            second = temp;

            output_tail = output_tail->next;

        }

        

        // Odd sized list

        if (first == second) {

            output_tail->next = first;

            first->next = NULL;

            output_tail = output_tail->next;

        }

        

        head = output_head->next;

    }

};