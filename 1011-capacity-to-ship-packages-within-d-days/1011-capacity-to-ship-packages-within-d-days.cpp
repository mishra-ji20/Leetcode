class Solution {
public:
    bool check(vector<int>&weights,int cap,int d)
    {
        int curr=0;
        int dn=0;
        for(int i=0;i<weights.size();i++)
        {
            curr+=weights[i];
            if(curr>cap)
            {
               dn++;
            curr=weights[i];
            }
        }
        dn++;
        if(dn>d)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int ma=0;
        for(int i=0;i<weights.size();i++)
        {
            sum=sum+weights[i];
            ma=max(ma,weights[i]);
        }
        int i=ma,j=sum;
        int ans;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(check(weights,mid,days))
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
            
        }
        return ans;
        
            
        
    }
};