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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fh = NULL, *ft = NULL;
        
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val < list2 -> val ){
                if(fh == NULL){
                    fh = list1;
                    ft = list1;
                }
                else{
                    ft -> next = list1;
                    ft = list1;
                }
                list1 = list1 -> next;
            }
            else{
                if(fh == NULL){
                    fh = list2;
                    ft = list2;
                }
                else{
                    ft -> next = list2;
                    ft = list2;
                }
                list2 = list2 -> next;
            }
        }
        
        if(list1 != NULL){
            ft -> next = list1;
        }
        if(list2 != NULL){
            ft -> next = list2;
        }
        
        return fh;
    }
};