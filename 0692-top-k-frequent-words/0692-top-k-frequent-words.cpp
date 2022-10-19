class Solution {
public:
    static bool comp(pair<int,string>&a,pair<int,string>&b)
    {
        if(a.first==b.first)
            return lexicographical_compare(a.second.begin(),a.second.end(),b.second.begin(),b.second.end());
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>q;
        vector<pair<int,string>>ans;
        for(auto it:mp)
        {
            int a=it.second;
            string b=it.first;
            ans.push_back({a,b});
        }
        vector<string>res;
        sort(ans.begin(),ans.end(),comp);
        for(int i=0;i<k;i++)
        {
            res.push_back(ans[i].second);
        }
        return res;
    }
};