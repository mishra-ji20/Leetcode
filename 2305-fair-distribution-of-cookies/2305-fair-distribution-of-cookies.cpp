class Solution {
public:
    void rec(vector<int> &cookies,vector<int> &arr,int i,int &ans,int ma)
    {
        if(i>=cookies.size())
        {
            ans=min(ans,ma);
            return;
        }
        for(int j=0;j<arr.size();j++)
        {
            arr[j]+=cookies[i];
            int tMa=max(ma,arr[j]);
            rec(cookies,arr,i+1,ans,tMa);
            arr[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>arr(k,0);
        int ans=INT_MAX;
        rec(cookies,arr,0,ans,0);
        return ans;
    }
};