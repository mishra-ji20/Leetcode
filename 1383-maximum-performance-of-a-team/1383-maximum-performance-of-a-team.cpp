class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        int mod=1000000007;
        vector<pair<long long int,long long int>>arr;
        for(int i=0;i<sp.size();i++)
        {
            arr.push_back({ef[i],sp[i]});
        }
        sort(arr.rbegin(),arr.rend());
        priority_queue<long long int,vector<long long int>,greater<long long int>>q;
        long long int sum=0;
        long long int res=0;
        for(int i=0;i<arr.size();i++)
        {
            if(q.size()<k)
            {
                sum=((sum)+(arr[i].second));
                q.push((arr[i].second));
                long long int res2=((sum)*((arr[i].first)));
                res=res2>res?res2:res;
            }
            else
            {
                if(arr[i].second>q.top())
                {
                    unsigned int a=q.top();
                    q.pop();
                    sum=sum-a;
                    sum=sum+arr[i].second;
                    q.push(arr[i].second);
                    long long int res2=((sum)*(arr[i].first));
                    res=res2>res?res2:res;  
                }
            }
            
        }
        // cout<<res<<" ";
        return (res%mod);
        
    }
};