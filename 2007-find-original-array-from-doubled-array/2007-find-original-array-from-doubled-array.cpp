class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        vector<int>ans;
        sort(arr.begin(),arr.end());
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==-1)
                continue;
            else
            {
                // cout<<arr[i]<<" ";
                if(mp[2*arr[i]].size()==0)
                    return ans;
                else if(arr[i]==0)
                {
                    if( mp[arr[i]].back()!=i)
                    {
                        arr[mp[arr[i]].back()]=-1;
                        mp[arr[i]].pop_back();
                        
                    }
                    else
                        return ans;
                   
                }
                else
                {
                    arr[mp[2*arr[i]].back()]=-1;
                    mp[2*arr[i]].pop_back();
                }
                
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=-1)
                ans.push_back(arr[i]);
        }
        return ans;
        
    }
};