class FrontMiddleBackQueue {
public:
    class Node{
        public:
        int val;
        Node* next;
        Node* prev;
        Node(int val){
            this->val=val;
            next=NULL;
            prev=NULL;
        }
        Node(int val,Node *prev,Node *next){
            this->val=val;
            this->next=next;
            this->prev=prev;
        }
    };
    int size;
    Node* head;
    Node* tail;
    FrontMiddleBackQueue() {
        size=0;
        head=NULL;
        tail=NULL;
        
    }
    
    void pushFront(int val) {
        if(size==0){
            head=new Node(val,NULL,NULL);
            tail=head;
        }else{
            head->prev=new Node(val,NULL,head);
            head=head->prev;
        }
        size++;
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl;
        
    }
    
    void pushMiddle(int val) {
        if(size<=1){
            return pushFront(val);
        }else{
            int mid=(size/2)-1;
            Node *curr=head;
            for(int i=0;i<mid;i++){
                curr=curr->next;
            }
            Node* temp=curr->next;
            curr->next=new Node(val,curr,temp);
            temp->prev=curr->next; 
        }
        size++;
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl;
        
    }
    void pushBack(int val) {
        if(size==0){
            return pushFront(val);
        }else{
            tail->next=new Node(val,tail,NULL);
            tail=tail->next;
        }
        size++;     
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl; 
    }
    
    int popFront() {
        int x=0;
        if(size==0){
            return -1;
        }else if(size==1){
            x=head->val;
            head=NULL;
            tail=NULL;
        }else{
            x=head->val;
            head=head->next;
            head->prev=NULL;
        }
        size--;       
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl;
        return x;
        
    }
    
    int popMiddle() {
        int x=0;
        if(size==0){
            return -1;
        }if(size<=2){
            return popFront();
        }else{
            int mid=(size/2);
            if(size%2==0){
                mid--;
            }
            Node* curr=head;
            for(int i=0;i<mid;i++) {
                curr=curr->next;
            }
            x=curr->val;
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
        }
       
        size--; 
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl;
        return x;
        
    }
    
    int popBack() {
        int x=0;
        if(size==0){
            return -1;
        }else if(size==1){
            return popFront();
        }else{
            x=tail->val;
            tail=tail->prev;
            tail->next=NULL;
        }
        size--; 
        // Node *temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        // cout<<"    "<<size<<endl;
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */