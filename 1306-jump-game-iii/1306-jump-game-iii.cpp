class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        if(arr[start]==0)
            return true;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            int a=q.size();
            while(a--)
            {
                int i=q.front();
                if(arr[i]==0)
                    return true;
                if(i+arr[i]<arr.size() && vis[i+arr[i]]==0){
                    q.push(i+arr[i]);
                    vis[i+arr[i]]=1;
                }
                if(i-arr[i]>=0 && vis[i-arr[i]]==0)
                {
                    q.push(i-arr[i]);
                    vis[i-arr[i]]=1;
                }
                q.pop();
            }
            
        }
        return false;
    }
};