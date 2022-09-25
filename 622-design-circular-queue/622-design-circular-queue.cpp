class MyCircularQueue {
public:
    class Node{
        public:
        int val;
        Node *next;
        Node(int a,Node *b)
        {
            val=a;
            next=b;
        }
    };
    int size;
    int n;
    Node* head= new Node(-1,NULL);
    Node* temp;
    MyCircularQueue(int k) {
        temp=head;
        size=k;
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        temp->next=new Node(value,NULL);
        temp=temp->next;
        size--;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        // cout<<size<<" ";
         size++;
        // cout<<size<<" ";
        if(head->next==temp)
            temp=head;
        head->next=head->next->next;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return head->next->val;
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        // cout<<temp->val<<" ";
        return temp->val;
        
    }
    
    bool isEmpty() {
        // cout<<"isEmpty"<<" "<<size<<" ";
        if(size>=n)
            return true;
        return false;
        
    }
    
    bool isFull() {
        if(size<=0)
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */