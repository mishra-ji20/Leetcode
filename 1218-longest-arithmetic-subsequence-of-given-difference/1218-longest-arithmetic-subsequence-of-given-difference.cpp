class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>mp;
        mp[arr[0]]=1;;
        int ma=INT_MIN;
        for(int i=1;i<arr.size();i++)
        {
            mp[arr[i]]=mp[arr[i]-difference]+1;
            ma=max(ma,mp[arr[i]]);
        }
        return ma;
    }
};