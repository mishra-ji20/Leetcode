class Solution {
public:
    bool static compare(vector<int> &v1, vector<int> &v2)
    {
        if(v1[0]==v2[0])
            return v1[1]<v1[1];
        return v1[0]<v2[0];
    }
    int search(vector<int> &arr, int a)
    {
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            // cout<<l<<" "<<h<<endl;
            int mid=(l+h)/2;
            if(arr[mid]==a)
                return mid;
            else if(arr[mid]<a)
            {
                l=mid+1;
            }
            else
                h=mid-1;
        }
    
        return l;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>height;
        sort(pairs.begin(),pairs.end(),compare);
        height.push_back(INT_MIN);
        int ma=0;
        for(int i=0;i<pairs.size();i++)
        {
           int a=search(height,pairs[i][0]);
             cout<<a<<" ";
            if(a==height.size())
                height.push_back(pairs[i][1]);
            ma=ma>height.size()?ma:height.size();
            height[a]=min(height[a],pairs[i][1]);
            
        }
        return ma-1;
        
    }
};