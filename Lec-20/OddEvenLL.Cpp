//problem link: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next ==NULL)
            return head;

        //divide ll into odd and even one
        ListNode* odd_l  =head;  //to store last node of odd ll
         ListNode* even_h=head->next;
         ListNode* even_l = head->next;
         ListNode* cur = head->next->next;
        int c=1;
        while(cur){
            if(c%2==1){
                odd_l->next=cur;
                odd_l = cur;
                cur = cur->next;

            }
            else{
                even_l->next=cur;
                even_l = cur;
                cur = cur->next;
            }

            c++;
        }

        //connect odd and even ll
        odd_l->next = even_h;
        even_l->next = NULL;
        return head;

    }
};
