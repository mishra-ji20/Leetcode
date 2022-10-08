class Solution {
public:
    bool check(vector<int>&piles,int k,int rq)
    {
       long long int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=(piles[i]/k)+((piles[i]%k)==0?0:1);
        }
        // cout<<sum<<" ";
        if(sum>rq)
            return false;
        else
            return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mi=1;
        int ma=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            mi=min(piles[i],mi);
            ma=max(piles[i],ma);
        }
        // cout<<mi<<" "<<ma;
        int ans=ma;
        while(mi<=ma)
        {
            int mid=(mi+ma)/2;
            int a=check(piles,mid,h);
            if(a)
            {
                ans=mid;
                ma=mid-1;
            }
            else
                mi=mid+1;
            
        }
        return ans;
        
    }
};