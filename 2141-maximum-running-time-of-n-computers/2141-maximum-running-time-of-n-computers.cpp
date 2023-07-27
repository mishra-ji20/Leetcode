class Solution {
public:
    int search(vector<long long >&arr,long long target)
    {
        int i=0;
        int j=arr.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(arr[mid]<=target)
                j=mid-1;
            else
                i=mid+1;
            
                
        }
        return i;
        
    }
    static bool comp(int &a,int &b){
        return a>b;
    }
    long long maxRunTime(long long n, vector<int>& bat) {
        sort(bat.begin(),bat.end(),comp);
        long long sum2=0;
        long long sum1=0;
        for(int i=0;i<bat.size();i++)
        {
            if(i<n)
                sum1+=bat[i];
            else
            sum2+=bat[i];
        }
        vector<long long>arr;
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
            // cout<<bat[i]<<' ';
            long long a=((long long)(bat[i])*(n-i))-(sum1-sum);
            // cout<<a<<" ";
            arr.push_back(a);
            sum+=bat[i];
        }
        // cout<<endl;
        int a=search(arr,sum2);
        // cout<<a<<" "<<sum2<<" ";
        if(a==n)
            return bat[a]+sum2;
        return bat[a]+((sum2-arr[a])/(n-a));
    }
};