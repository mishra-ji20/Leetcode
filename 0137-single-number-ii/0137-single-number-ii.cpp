class Solution {
public:
    long long pow(int n){
        long long a=1;
        for(int i=1;i<=n;i++)
        {
            a=(long long)2*a;
        }
        return a;
    }

    void bits(long long num,vector<int>&arr)
    {
        int i=0;
        while(num)
        {
            if(num&1){
                arr[i]++;
            }
            i++;
            num=num>>1;
            // cout<<num<<" ";
        }
    }
    int singleNumber(vector<int>& nums) {
        vector<int>arr(33,0);
        for(int i=0;i<nums.size();i++)
        {
            long long a=nums[i];
            if(nums[i]<0)
            {
                a=a&(pow(31)-1); 
                a=a|(pow(32));
            }
            // cout<<a<<" ";
            bits(a,arr);
        }
        long long sum=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            arr[i]=arr[i]%3;
            // cout<<arr[i]<<" ";
            if(arr[i])
            sum+=pow(i);
        }
        // cout<<arr[32]<<" ";
        // cout<<sum<<" ";
        if(arr[32]%3){
            // cout<<"hdjsh";
           long long a=sum-pow(31);
            int b=a;
            return b;
        }
        return sum;
    }
};