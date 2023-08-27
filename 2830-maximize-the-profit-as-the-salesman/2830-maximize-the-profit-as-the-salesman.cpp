class Solution {
public:
    int search(vector<int> &index,int t){
        int i=0,j=index.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(index[mid]==t)
                return mid;
            if(index[mid]>t)
                j=mid-1;
            else
                i=mid+1;
        }
        return i;
        
    }
    bool static comp(vector<int> &a, vector<int> &b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),comp);
        vector<int>index;
        index.push_back(0);
        vector<int>dp;
        dp.push_back(0);
        int ma=0;
        for(int i=0;i<offers.size();i++)
        {
            int a=search(index,offers[i][0]+1);
            // cout<<a<<' ';
            if(offers[i][1]+1!=index[index.size()-1])
            {
                index.push_back(offers[i][1]+1);
                dp.push_back(max(dp[dp.size()-1],dp[a-1]+offers[i][2]));
                
            }
            else
                dp[dp.size()-1]=max(dp[a-1]+offers[i][2],dp[dp.size()-1]);
            
            // for(int i=0;i<dp.size();i++)
            // {
            //     cout<<dp[i]<<" ";
            //     cout<<index[i]<<"\t";
            // }
            // cout<<endl;
            ma=max(ma,dp[dp.size()-1]);
        }
        return ma;
        
    }
};