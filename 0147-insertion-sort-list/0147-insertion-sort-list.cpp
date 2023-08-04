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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode *dummyHead=new ListNode(-5001,insertionSortList(head->next));
        ListNode* temp1=head;
        ListNode* temp2=dummyHead->next;
        ListNode* prev=dummyHead;
        while(temp2 && temp2->val<temp1->val)
        {
            prev=temp2;
            temp2=temp2->next;
        }
        temp1->next=temp2;
        prev->next=temp1;
        return dummyHead->next;
        
    }
};