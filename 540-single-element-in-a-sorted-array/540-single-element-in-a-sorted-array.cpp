class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        if(arr.size()==1)
            return arr[0];
        int i=0;
        int j=arr.size()-1;
        while(i<=j)
        {
            // cout<<i<<" "<<j<<" ";
            if(i==j)
                return arr[i];
            int mid=(i+j)/2;
            if(arr[mid]==arr[mid-1])
            {
                if((mid-1-i)%2==1)
                {
                    j=mid-2;
                }
                else
                    i=mid+1;
            }
           else if(arr[mid]==arr[mid+1])
            {
                if((j-mid+1)%2==1)
                {
                    i=mid+2;
                }
                else
                    j=mid-1;
            }
            else
                return arr[mid];
        }
        return 0;
        
    }
};