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
    void sol(ListNode* h1,ListNode *h2,int &carry,int diff,ListNode* &res)
    {
        if(h2==NULL)
            return;
        if(diff)
        sol(h1->next,h2,carry,diff-1,res);
        else
        sol(h1->next,h2->next,carry,diff,res);
        
        int a,b;
        if(diff==0)
            b=h2->val;
        else
            b=0;
        
        // cout<<h1->val<<" "<<b<<endl;
        ListNode* temp=new ListNode((h1->val+b+carry)%10,res->next);
        carry=(h1->val+b+carry)/10;
        res->next=temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*res=new ListNode(-1,NULL);
        ListNode *h1=l1,*h2=l2;
        int s1 =0,s2=0;
        while(h1 || h2)
        {
            if(h1){
                s1++;
                 h1=h1->next;
            }
            if(h2)
            {
                s2++;
                h2=h2->next;
            }
           
            
        }
        int carry=0,cnt=0;
        if(s1>s2)
            sol(l1,l2,carry,abs(s2-s1),res);
        else
            sol(l2,l1,carry,abs(s2-s1),res);
        if(carry){
             ListNode* temp=new ListNode(carry,res->next);
             res->next=temp;
        }
            
        return res->next;   
    }
};