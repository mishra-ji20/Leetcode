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
    void rec(ListNode* temp,int n ,int curr,ListNode* &nt,int &ans)
    {
        if(curr==(n/2)+1)
        {
            return ;
        }
        nt=nt->next;
        rec(temp->next,n,curr+1,nt,ans);
        ans=max(ans,temp->val+nt->val);
        nt=nt->next;
          
    }
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        int ans=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
         temp=head;
        rec(head,n,1,temp,ans);
        return ans;
            
    }
};