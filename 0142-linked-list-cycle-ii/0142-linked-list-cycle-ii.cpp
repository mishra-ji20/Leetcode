/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode *temp1,*temp2,*temp3;
        temp1=head->next;;
        temp3=head;
        if(temp1 && temp1->next)
            temp2=temp1->next;
        else
            return NULL;
        while(temp1!=temp2 && temp2 && temp2->next)
        {
            temp1=temp1->next;
            temp2=temp2->next->next;
            if(temp1==temp2)
                break;
        }
        if(temp1==temp2)
            temp2=temp1->next;
        else
            return NULL;
        int a=0,b=0;
        while(temp3!=temp1)
        {
            temp3=temp3->next;
            a++;
        }
        while(temp2!=temp1)
        {
            temp2=temp2->next;
            b++;
        }
        temp2=temp1->next;
        temp3=head;
        while(a>b)
        {
            temp3=temp3->next;
            a--;
        }
        while(a<b)
        {
            temp2=temp2->next;
            b--;
        }
        ListNode *prev=temp2;
        while(temp3!=temp2)
        {
            temp3=temp3->next;
            prev=temp2;
            temp2=temp2->next;
        }
        return temp3;
        
    }
};