class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        vector<int>ans(barcodes.size(),0);
        int mai=barcodes[0];
        for(int i=0;i<barcodes.size();i++)
        {
            mp[barcodes[i]]++;
            if(mp[mai]<mp[barcodes[i]])
                mai=barcodes[i];
        }
        int i=0;
        for(int j=0;j<mp[mai];i=i+2,j++)
        {
            ans[i]=mai;
        }
        if(i>=barcodes.size())
            i=1;
        mp[mai]=0;
        for(auto it:mp)
        {
            if(it.first!=0)
           for(int j=0;j<it.second;j++)
           {
               if(i>=barcodes.size())
                   i=1;
               ans[i]=it.first;
               i+=2;
           }
        }
        return ans;
    }
};