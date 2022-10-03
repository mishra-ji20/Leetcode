class Solution {
public:
    int minCost(string col, vector<int>& nt) {
        int ans=0;
        for(int i=0;i<col.size();)
        {
           
            int j=i;
            int sum=0;
            int mi=INT_MIN;
            while(j<col.size() && col[i]==col[j])
            {
                sum=sum+nt[j];
                mi=max(mi,nt[j]);
                j++;
            }
            // cout<<sum<<" "<<mi<<endl; 
            ans=ans+sum-mi;
            i=j;
        }
        return ans;
        
    }
};