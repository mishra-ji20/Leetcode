/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void func(Node* head,Node* &first,Node* &last)
    {
        if(head->next==NULL)
        {
            last=head;
        }
        if(head->child){
            Node* temp=head->child;
            func(head->child,temp,last);
            Node *temp1=head->next;
            head->next=temp;
            if(temp)temp->prev=head;
            last->next=temp1;
            if(temp1)temp1->prev=last;
            head->child=NULL;
            if(temp1){
            head=temp1;
            last=temp1;
            }
            else{
            head=last;
            }
        }
        if(head->next)
        func(head->next,first,last);
        
        
        
    }
    Node* flatten(Node* head) {
        if(head==NULL)
            return head;
        Node *temp1=head;
        Node* temp2=NULL;
        func(head,temp1,temp2);
        return temp1;
        
    }
};