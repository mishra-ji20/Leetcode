class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int search(vector<pair<int,int>> &arr,int t,int x)
    {
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            int mid=((l+h)/2);
            if(arr[mid].first<t && arr[mid].second!=x)
                l=mid+1;
            else
                h=mid-1;
        }
        return l;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       
        vector<pair<int,int>>arr2;
        sort(envelopes.begin(),envelopes.end(),comp);
       
        arr2.push_back({0,0});
        // arr2.push_back({envelopes[0][1],envelopes[0][0]});
        int ma=1;
        for(int i=0;i<envelopes.size();i++)
        {
            // cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<" ";
            
            int b=search(arr2,envelopes[i][1],envelopes[i][0]);
            if(b==arr2.size())
                 arr2.push_back({envelopes[i][1],envelopes[i][0]});
            // cout<<b<<" ";
            if(arr2[b].first>envelopes[i][1])
            {
                arr2[b].first=envelopes[i][1];
                arr2[b].second=envelopes[i][0];
            }
            ma=ma>arr2.size()-1?ma:arr2.size()-1;
            
        }
        // for(int i=0;i<arr2.size();i++)
        // {
        //     cout<<arr2[i].first<<" ";
        // }
        return ma;
        
    }
};