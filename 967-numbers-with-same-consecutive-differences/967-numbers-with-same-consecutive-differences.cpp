class Solution {
public:
    unordered_map<int,int>mp;
    void recur(int i,int count,long long int sum,vector<int>&ans,int &k,int &n)
    {
       
        if(count==n)
        {
            if(mp[sum]==0)
            ans.push_back(sum);
            mp[sum]=1;
            return;
        }
        if(i-k>=0) recur(i-k,count+1,sum*10+i-k,ans,k,n);
        if(i+k<=9)recur(i+k,count+1,sum*10+i+k,ans,k,n);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
       for(int i=1;i<=9;i++)
       {
           int count=1;
           long long int sum=i;
           recur(i,count,sum,ans,k,n);
       }
        return ans;
    }
};