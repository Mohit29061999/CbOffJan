//problem link: https://leetcode.com/problems/palindrome-linked-list/

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


ListNode* reverseLL(ListNode* head){
    ListNode* curr=head;
    ListNode* prev =NULL;
    while(curr!=NULL){
        //store next first else we will loose it
        ListNode* n = curr->next;

        //current node ko reverse karo
        curr->next = prev;

        //next node ko reverse karo
        prev=curr;
        curr =n;
    }

    //prev is our new head so return it
    return prev;
}
ListNode* getMid(ListNode* head){
    ListNode* s=head;
    ListNode* f=head->next;

    //move slow by 1 and fast by 2
    while(f!=NULL && f->next !=NULL){
        s=s->next;
        f=f->next;
        f=f->next;
    }

    //slow will point to mid
    return s;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //base case
        if(head==NULL || head->next==NULL)
            return true;

        //get the middle node
        ListNode* mid = getMid(head);

        //reverse second half
        ListNode* secondHalf = reverseLL(mid->next);

        while(secondHalf!=NULL){
            if(head->val !=secondHalf->val)
                return false;
            head=head->next;
            secondHalf  = secondHalf->next;
        }

        return true;


    }
};
