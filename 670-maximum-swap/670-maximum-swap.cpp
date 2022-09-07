class Solution {
public:
    int maximumSwap(int num) {
        if(num==0)
            return 0;
        vector<int>arr;
        while(num)
        {
            arr.push_back(num%10);
            num=num/10;
        }
        reverse(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++)
        //     cout<<arr[i]<<" ";
        for(int i=0;i<arr.size()-1;i++)
        {
            int ind=i;
            bool flag=0;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[ind]<=arr[j])
                {
                    if(arr[ind]==arr[j] && flag)
                    {
                        ind=j;
                    }
                    else if(arr[ind]<arr[j])
                    {
                        ind=j;
                        flag=1;
                    }
                }
            }
            if(flag)
            {
                swap(arr[ind],arr[i]);
                break;
            }
        }
        int sum=0;
         for(int i=0;i<arr.size();i++)
            sum=sum*10+arr[i];
        
        
        return sum;
        
    }
};