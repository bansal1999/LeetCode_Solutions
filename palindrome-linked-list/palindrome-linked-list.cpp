class Solution {
public:
		// for finding middle of linked list
        ListNode* find_middle(ListNode* head,int n)
        {
            ListNode *slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            if(n&1)
                return slow->next;
            else
                return slow;
        }
		// for reversing the linked-list
        ListNode* reverse_link(ListNode* head)
        {
            ListNode *prev=NULL;
            ListNode *curr=head;
            ListNode *next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        
        ListNode *temp=head;
        // loop for counting number of nodes i.e odd or even
        int n=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            n++;
        }
        temp=head;
        // will return middle node for reversing linked-list
        ListNode *head_mid=find_middle(temp,n);
        // will reverse the second half linked-list
        ListNode *head_rev=reverse_link(head_mid);
        // will check first half and second half of linked-list is equal of not
        while(head_rev!=NULL)
        { 
            // if value of nodes in between is not equal then not palindrome
            if(head->val!=head_rev->val)
                return false;
            
            head_rev=head_rev->next;
            head=head->next;
        }
        // if value of every nodes of both half are equal then it is palindrome
        return true;
    }
};