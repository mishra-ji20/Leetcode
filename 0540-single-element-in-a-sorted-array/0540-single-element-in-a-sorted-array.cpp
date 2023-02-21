class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size()==1)
            return arr[0];
        int l=0;
        int h=arr.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(mid-1>=l && mid+1<=h)
            {
                if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])
                    return arr[mid];
               else if(arr[mid]==arr[mid+1])
                {
                   if((h-mid+1)%2)l=mid+2;
                   else
                       h=mid-1;
                }
                else{
                   if((mid-1-l)%2)h=mid-2;
                   else
                       l=mid+1;
                }
            }
            
        }
        return arr[l];
       
    }
};