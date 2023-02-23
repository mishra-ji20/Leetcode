class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        set<pair<int,int>>st;
        vector<pair<int,int>>arr;
        int a=0;
        for(int i=0;i<profits.size();i++)
        {
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());
        int sum=w;
        for(int i=0;i<arr.size();)
        {
            if(k==0)
                return sum;
            while(i<arr.size() && w>=arr[i].first)
            {
                // cout<<arr[i].first<<endl;
                st.insert({-arr[i].second,i});
                i++;
            }
            if(st.empty())
                return sum;
            else
            {
                sum=sum+(-st.begin()->first);
                w=sum;
                k--;
                st.erase({st.begin()->first,st.begin()->second});
            }
        }
        // for(auto it: st)
        // {
        //     cout<<it.first<<" "<<it.second<<" ";
        // }
        while(k-- && !st.empty())
        {
                sum=sum-st.begin()->first;
                st.erase({st.begin()->first,st.begin()->second});
        }
        return sum;
        
    }
};