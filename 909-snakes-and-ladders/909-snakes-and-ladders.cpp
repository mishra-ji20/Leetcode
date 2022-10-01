class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int t=board.size()*board.size();
        queue<int>q;
        q.push(1);
        int count=0;
        vector<int>vis(t+1,0);
        while(!q.empty())
        {
           
            int s=q.size();
            while(s--){
            int a=q.front();
                // cout<<a<<" ";
                if(a==t)
                    return count;
            for(int i=1;i<=6;i++){
                int r=n-((a+i-1)/n)-1;
                    int c;
                    if((n-r)%2==0){
                        c=n-((a+i-1)%n)-1;
                        // cout<<'a';
                    }
                    else {
                        c=(a+i-1)%n;
                        // cout<<'b';
                    }
                if(a+i<=t){
                    
                     // cout<<r<<" "<<c<<endl;
                    if(board[r][c]==-1)
                    {
                        if(vis[a+i]==0)
                        q.push(a+i);
                        vis[a+i]=1;
                    }
                    else if(vis[board[r][c]]==0){
                        q.push(board[r][c]);
                        vis[board[r][c]]=1;
                    }
                }
            }
                q.pop();
            }
            count++;
        }
        return -1;
            
    } 
};