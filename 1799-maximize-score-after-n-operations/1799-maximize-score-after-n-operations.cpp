class Solution {
public:
    
    int backtrack(vector<int> &nums, vector<int> vis,vector<int> &dp,int index,int k){
        // for(int i=0;i<vis.size();i++)
        //     cout<<vis[i]<<" ";
        // cout<<endl;
        if(k>nums.size()/2)
            return 0;
        // cout<<(index)<<" ";
        if(dp[index]!=-1)
            return dp[(index)];
        for(int i=0;i<nums.size();i++)
        {   
            for(int j=i+1;j<nums.size();j++)
            {
                
                if(vis[j]==0 && vis[i]==0)
                {
                    // cout<<i<<" "<<j<<" ";
                    int nindex=index |(1<<i);
                    int x=0;
                    vis[i]=1;
                    vis[j]=1;
                    nindex=nindex | (1<<j);
                    // cout<<nindex<<endl;
                    x=k*(__gcd(nums[i],nums[j]))+backtrack(nums,vis,dp,nindex,k+1);
                    dp[(index)]=max(dp[(index)],x);
                    vis[i]=0;
                    vis[j]=0;
                    
                }
            }
               
                
            }
        
        return dp[(index)];
        
    }
    int maxScore(vector<int>& nums) {
        int mask=pow(2,nums.size())-1;
        int num=0;
        vector<int>vis(nums.size(),0);
        vector<int>dp(mask+1,-1);
       int a= backtrack(nums,vis,dp,num,1);
        return a;
        
    }
};