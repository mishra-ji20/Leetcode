class Trie {
public:
   
    class Trienode{
        
       public:
        Trienode *child[26];
        bool ie;
        Trienode()
        {
            memset(child,NULL,sizeof(child));
            ie=0;
        }
       
    };
    Trienode *root;
    
    Trie() {
        root=new Trienode();
    }
    
    void insert(string word) {
        Trienode* temp=root;
        for(int i=0;i<word.size();i++)
        {
            // cout<<word[i]-'a'<<" ";
            if(temp->child[word[i]-'a']==NULL)
            {
                temp->child[word[i]-'a']=new Trienode();
            }
                temp=temp->child[word[i]-'a'];
                
        }
        temp->ie=1; 
    }
    
    bool search(string word) {
        Trienode *temp=root;
        // bool ans=true;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a'])
                temp=temp->child[word[i]-'a'];
            else
                return false;
        }
        if(temp->ie)
            return true;
        else
            return false; 
    }
    
    bool startsWith(string word) {
        Trienode *temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->child[word[i]-'a'])
                temp=temp->child[word[i]-'a'];
            else
                return false;
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */