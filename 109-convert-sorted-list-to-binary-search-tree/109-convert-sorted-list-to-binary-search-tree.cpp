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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    
    TreeNode* helper(vector<int> arr, int left, int right)
    {
        if(left > right)
        {
            return NULL;
        }
        
        int mid = (left + right)/2;
        
        TreeNode* root = new TreeNode(arr[mid]);        
        root->left = helper(arr,left, mid -1);
        root-> right = helper(arr, mid + 1, right);
        
        return root;
    }
     
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        // sortedArray(head, arr);
        
         while(head != NULL)
        {
            arr.push_back(head -> val);
            head = head -> next;
        }
        
        return helper(arr, 0, arr.size() -1);
    }
};