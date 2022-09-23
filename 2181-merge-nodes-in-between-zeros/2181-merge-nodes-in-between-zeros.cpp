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
        ListNode* res=new ListNode(-1,head);
        ListNode* ans=res;
        head=head->next;
        while(head)
        {
            long sum=0;
            while(head->val!=0)
            {
                sum=sum+head->val;
                head=head->next;
            }
            ListNode* temp=head->next;
            head->val=sum;
            ans->next=head;
            ans=head;
            head->next=NULL;
            head=temp;
        }
        return res->next;
    }
};