class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++) {
            arr[s[i]-'a']++;
        }
        sort(arr.begin(),arr.end());
        int j=25;
        int curr=INT_MAX;
        int count=0;
        while(j>=0 && arr[j]!=0) {
            if(arr[j]>=curr) {
                count+=arr[j]-((curr-1)<0?0:(curr-1));
                arr[j]=((curr-1)<0?0:(curr-1));
                curr=((curr-1)<0?0:(curr-1));
            } else {
                curr=arr[j];
            }
            j--;
            
            
        }
        return count;
      
        
    }
};