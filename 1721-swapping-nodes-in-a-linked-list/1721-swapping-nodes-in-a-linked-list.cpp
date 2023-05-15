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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr=head,*temp1=head,*temp2=head;
        while(k>1){
            temp1=temp1->next;
            ptr=ptr->next;
            k--;
        }
        while(ptr->next){
            temp2=temp2->next;
            ptr=ptr->next;
        }
        int temp=temp1->val;
        temp1->val=temp2->val;
        temp2->val=temp;
        
        return head;
        
    }
};