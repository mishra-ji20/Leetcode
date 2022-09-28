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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *first=head;
        for(int i=0;i<n;i++)
            first=first->next;
        ListNode *temp=head;
        if(first==NULL){
            head=head->next;
            return head;
        }
        while(first->next)
        {
            temp=temp->next;
            first=first->next;
        }
        temp->next=temp->next->next;
        return head;   
    }
};