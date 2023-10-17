class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool>vis(n,false);
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++) {
            if(leftChild[i]!=-1) {
                parent[leftChild[i]]=i;
            }
            if(rightChild[i]!=-1) {
                parent[rightChild[i]]=i;
                
            }
        }
        int i=0;
        vector<bool>visTemp(n,false);
        int prev=0;
        
        while(visTemp[i]==false && parent[i]!=-1) {
            visTemp[i]=true;
            i=parent[i];
            
        }
        if(visTemp[i]==true)return false;
        
        // cout<<i<<' ';
        // cout<<endl;
        queue<int>q;
        q.push(i);
        vis[i]=true;
        int cnt=1;
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                int a=q.front();
                q.pop();
                if(leftChild[a]!=-1) {
                    if(vis[leftChild[a]]==false) {
                        cnt++;
                        q.push(leftChild[a]);
                        vis[leftChild[a]]=true;
                    }else {
                        return false;
                    }
                } 
                if(rightChild[a]!=-1) {
                    if(vis[rightChild[a]]==false) {
                        cnt++;
                        q.push(rightChild[a]);
                        vis[rightChild[a]]=true;
                    } else {
                        return false;
                    }
                } 
            }
        }
        if(cnt!=n){
            return false;
        }
        
        return true;
        
    }
};