class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        int i=0,j=mp[key].size()-1;
        pair<int,string>ans={-1,""};
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(mp[key][mid].first==timestamp){
                ans=mp[key][mid];
                return ans.second;
            }
            if(mp[key][mid].first<timestamp)
            {
                ans=mp[key][mid];
                i=mid+1;
            }
            else
                j=mid-1;
            
        }
        return ans.second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */