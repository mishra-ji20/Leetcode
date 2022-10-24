class Solution {
public:
    int check(vector<int>mp)
    {
        int count=0;
        for(int i=0;i<mp.size();i++)
        {
            if(mp[i]>1)
            {
                return -1;
            }
            else if(mp[i]==1)
                count++;
        }
        return count;
    }
    void recur(vector<string>&arr,vector<int>mp,int i,int &ans)
    {
        
        if(check(mp)==-1)
        {
            return;
        }
        else{
            ans=max(ans,check(mp));
        }
        if(i>=arr.size())
            return ;
        recur(arr,mp,i+1,ans);
        for(int j=0;j<arr[i].size();j++)
        {
            mp[arr[i][j]-'a']++;
        }
        recur(arr,mp,i+1,ans);
    }
    int maxLength(vector<string>& arr) {
        int ans=0;
        vector<int>mp(26,0);
        recur(arr,mp,0,ans);
        return ans;
    }
};