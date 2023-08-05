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
    ListNode* reverse(ListNode* head, ListNode* temp1)
    {
        // cout<<head->val<<" ";
        // if(temp1)
        //     cout<<temp1->val<<' ';
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head->next;
        while(temp !=temp1)
        {
            curr->next=prev;
            prev=curr;
            curr=temp;
            temp=temp->next;
        }
        curr->next=prev;
        // cout<<endl;
            // return prev;
        return curr;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        int group=1;
        
        while(temp)
        {
            int cnt=0;
            // cout<<temp->val<<" "<<group<<" ";
            ListNode* temp1=temp;
            ListNode* prev1;
            // cout<<group<<" ";
            while(cnt<group && temp1)
            {
                prev1=temp1;
                // cout<<temp1->val<<' ';
                temp1=temp1->next;
                cnt++;
            }
            if(cnt %2==0)
            {
                // cout<<temp->val<<" "<<prev->val<<endl;
                prev->next= reverse(temp,temp1);
                // cout<<prev->next->val<<" ";
                // cout<<temp->val<<" ";
                // cout<<temp1->val;
                temp->next=temp1;
                prev=temp;
            }
            else{
                prev=prev1;
            }
            
            temp=temp1;
            group++;
        }
        return head;
        
    }
};