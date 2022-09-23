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
    ListNode* rev(ListNode* head)
    {
        ListNode* curr=head,*prev=NULL,*temp=head->next;
        while(curr)
        {
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(temp)
            temp=temp->next;
        }
        return prev;  
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* nh=new ListNode(-1,head);
        ListNode* temp1=nh,*temp2=nh,*temp3=nh,*temp4=nh->next,*temp=nh->next;
        int a=1;
        int b=n-m+1;
        while(a<=n)
        {
            if(a==b)
            {
                temp1=temp2;
                temp2=temp2->next;
                b++;
            }
            temp=temp->next;
            temp3=temp4;
            temp4=temp4->next;
            a++;
        }
        
        temp3->next=NULL;
        temp=rev(temp2);
        temp1->next=temp;
        temp2->next=temp4;
        return nh->next;
    }
};