class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int ma=values[0];
        int ans=INT_MIN;
        for(int i=1;i<values.size();i++)
        {
            ans=max(ma+values[i]-i,ans);
            ma=max(ma,values[i]+i);
            // cout<<ma<<" ";
        }
        return ans;
        
    }
};