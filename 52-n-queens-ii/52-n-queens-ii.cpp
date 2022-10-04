class Solution {
public:
    void recur(vector<vector<int>>vis,int x,int y,int &count,int n){
        if(x==n-1)
        {
            count++;
            return ;
        }
        int i=x;
        int j=y;
        for(int a=0;a<n;a++){
             vis[i][a]=1;
        }
        for(int a=0;a<n;a++){
           vis[a][j]=1;
        }
        int a=i,b=j;
        while(a<n && b<n)
        {
            vis[a][b]=1;
            a++;
            b++; 
        }
        a=i;
        b=j;
        while(a<n && b>=0)
        {
            vis[a][b]=1;
            a++;
            b--;
                        
        }
        a=i;
        b=j;
        while(a>=0 && b>=0)
        {
             vis[a][b]=1;
                a--;
                b--; 
        }
        a=i;
        b=j;
        while(a>=0 && b<n)
        {
            vis[a][b]=1;
            a--;
            b++; 
        }
        a=i;
        b=j;
        i=x+1;
        for(int j=0;j<n;j++)
        {
            
            if(vis[i][j]==0){
            vis[i][j]=1;
            recur(vis,i,j,count,n);
            }
        }
    }
    int totalNQueens(int n) {
        int count=0;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            vis[0][i]=1;
            recur(vis,0,i,count,n);
        }
        return count;
        
    }
};