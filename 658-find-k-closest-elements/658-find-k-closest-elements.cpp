class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int i=0;
        vector<int>ans;
        while( i<arr.size() && x>arr[i])
        {
            i++;
        }
        int j=i-1;
        int cnt=0;
        while((j>=0 && i<arr.size()) && cnt<k)
        {
            if(abs(arr[i]-x)<abs(arr[j]-x))
            {
                ans.push_back(arr[i]);
                i++;
                cnt++;
            }
            else if((abs(arr[i]-x)>=abs(arr[j]-x)))
            {
                ans.push_back(arr[j]);
                j--;
                cnt++;
            }   
        }
        while(i<arr.size() && cnt<k)
        {
            ans.push_back(arr[i]);
            i++;
            cnt++;
        }
         while(j>=0 && cnt<k)
        {
            ans.push_back(arr[j]);
            j--;
            cnt++;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};