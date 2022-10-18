class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        if(k==1)
            return rolls.size()+1;
        unordered_map<int,int>mp;
        set<pair<int,int>>st;
        int mi=0;
        for(int i=1;i<=k;i++)
        {
            st.insert({0,i});
            
        }
       
        for(int i=0;i<rolls.size();i++)
        {
            pair<int,int>f={mp[rolls[i]],rolls[i]};
            st.erase(f);
            // cout<<st.begin()->first<<" ";
            // /
            if(mp[rolls[i]]==mi)
            { 
                mp[rolls[i]]++;
                // cout<<rolls[i]<<" "<<mp[rolls[i]]<<" "<<i<<endl;
            }
            st.insert({mp[rolls[i]],rolls[i]});
            mi=st.begin()->first;
             
        }
        return st.begin()->first+1; 
    }
};