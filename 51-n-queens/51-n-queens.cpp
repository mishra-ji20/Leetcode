class Solution {
public:
    vector<vector<string>>help;
    void recur(int n,vector<string>ans,vector<vector<int>>vis,int sz,int x,int y){
    if(x==n-1)
    {
        help.push_back(ans);
        return;
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
            // cout<<a<<" "<<b<<" ";
            vis[a][b]=1;
            a++;
            b++; 
        }
        a=i;
        b=j;
        while(a<n && b>=0)
        {
            // cout<<a<<" "<<b<<" ";
            vis[a][b]=1;
            a++;
            b--;
                        
        }
        a=i;
        b=j;
        while(a>=0 && b>=0)
        {
             // cout<<a<<" "<<b<<" ";
             vis[a][b]=1;
                a--;
                b--; 
        }
        a=i;
        b=j;
        while(a>=0 && b<n)
        {
             // cout<<a<<" "<<b<<" ";
            vis[a][b]=1;
            a--;
            b++; 
        }
        a=i;
        b=j;
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<ans[i][j]<<" ";
        //     cout<<endl;
        //     }
        // cout<<endl;
        i=x+1;
         for(j=0;j<n;j++)
            {
                if(vis[i][j]==0)
                {
                    // cout<<i<<" "<<j<<" ";
                    vis[i][j]=1;
                    ans[i][j]='Q';
                    recur(n,ans,vis,sz-1,i,j);
                    ans[i][j]='.';
                    // vis[i][j]=0;
                    // cout<<i<<" "<<j<<" ";
                }
            
            }
    }
    vector<vector<string>> solveNQueens(int n) {
        string a;
        for(int i=0;i<n;i++)
            a.push_back('.');
        vector<string>ans(n,a);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)
        //         cout<<ans[i][j]<<" ";
        //     cout<<endl;
        //     }
        vector<vector<int>>vis(n,vector<int>(n,0));
       
            for(int j=0;j<n;j++){
                if(vis[0][j]==0){
                    // cout<<i<<" "<<j<<" ";
                    vis[0][j]=1;
                    ans[0][j]='Q';
                    recur(n,ans,vis,n-1,0,j);
                    // vis[i][j]=0;
                    ans[0][j]='.';
                }
            }
        return help;
        
    }
};