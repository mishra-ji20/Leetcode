class LRUCache {
public:
    class ListNode{
        public:
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v,ListNode* a,ListNode* b){
            val=v;
            next=a;
            prev=b;
        }
    };
    int size;
    unordered_map<int,ListNode*>mp;
    unordered_map<ListNode*,int>vk;
    int l;
    ListNode* head=new ListNode(-1,NULL,NULL);
    ListNode* tail=new ListNode(-1,NULL,head);
   
    LRUCache(int capacity) {
        l=0;
        size=capacity;
        head->next=tail;
    }
    
    int get(int key) {
        if(mp[key]==NULL)
            return -1;
            
            ListNode* temp=mp[key];
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->prev=tail->prev;
            temp->next=tail;
            tail->prev->next=temp;
            tail->prev=temp;
            mp[key]=temp;
            vk[temp]=key;
            return temp->val;
        
    }
    
    void put(int key, int value) {
        if(mp[key]==NULL && l==size )
        {
            // cout<<head->next->val<<" ";
            mp[vk[head->next]]=NULL;
            head->next->next->prev=head;
            head->next=head->next->next;
            l--;
        }
        if(mp[key]==NULL)
        {
            ListNode* temp=new ListNode(value,tail,tail->prev);
            tail->prev->next=temp;
            tail->prev=temp;
            mp[key]=temp;
            vk[temp]=key;
            l++;
        }
        else
        {
            ListNode* temp=mp[key];
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->prev=tail->prev;
            temp->next=tail;
            temp->val=value;
            tail->prev->next=temp;
            tail->prev=temp;
            mp[key]=temp;
            vk[temp]=key;
            
        }
        ListNode* curr=head->next;
//         while(curr!=tail)
//         {
//             cout<<curr->val<<" ";
//             curr=curr->next;
//         }
//         cout<<endl;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */