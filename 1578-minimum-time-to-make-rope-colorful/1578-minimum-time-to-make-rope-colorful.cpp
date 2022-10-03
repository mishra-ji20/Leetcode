class Solution {
public:
    int minCost(string col, vector<int>& nt) {
        int ans=0;
        for(int i=0;i<col.size();)
        {
            priority_queue<int>pq;
            int j=i;
            int sum=0;
            while(j<col.size() && col[i]==col[j])
            {
                sum=sum+nt[j];
                pq.push(nt[j]);
                j++;
            }
            // cout<<sum<<" "<<pq.top()<<" "; 
            ans=ans+sum-pq.top();
            i=j;
        }
        return ans;
        
    }
};