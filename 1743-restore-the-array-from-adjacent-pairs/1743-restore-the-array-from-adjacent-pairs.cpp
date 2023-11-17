class Solution {
public:
    void dfs(int a,vector<int>graph[],int prev,vector<int> &ans)
    {
        ans.push_back(a);
        for(int i=0;i<graph[a].size();i++) {
            if(graph[a][i]!=prev)
            dfs(graph[a][i],graph,a,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& nums) {
       unordered_map<int,int>mp;
        unordered_map<int,int>mpr;
        int j=1;
        for(int i=0;i<nums.size();i++) {
            if(mp[nums[i][0]]==0) {
                mp[nums[i][0]]=j++;  
                mpr[j-1]=nums[i][0];
            }
            if(mp[nums[i][1]]==0)
            {
                mp[nums[i][1]]=j++;
                mpr[j-1]=nums[i][1];
            }
        }
        vector<int>graph[nums.size()+2];
        for(int i=0;i<nums.size();i++) {
            graph[mp[nums[i][0]]].push_back(mp[nums[i][1]]);
            graph[mp[nums[i][1]]].push_back(mp[nums[i][0]]);
        }
        vector<int>ans;
        for(int i=1;i<nums.size()+2;i++) {
            if(graph[i].size()==1){
                dfs(i,graph,-1,ans);
                break;
            }
        }
        for(int i=0;i<ans.size();i++){
            ans[i]=mpr[ans[i]];
        }
        return ans;
        
    }
};