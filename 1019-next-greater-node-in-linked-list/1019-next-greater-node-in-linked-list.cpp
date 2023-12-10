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
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode *temp=head;
        stack<pair<ListNode*,int>>st;
        int i=0;
        while(temp){
            i++;
            temp=temp->next;
        }
        vector<int>ans(i,0);
        temp=head;
        i=0;
        while(temp){
            while(!st.empty() && st.top().first->val<temp->val){
                auto a=st.top();
                st.pop();
                ans[a.second]=temp->val;
            }
            st.push({temp,i});
            temp=temp->next;
            i++;
        }
        return ans;
        
    }
};