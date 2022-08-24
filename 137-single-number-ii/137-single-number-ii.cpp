class Solution {
public:
   long int power(int n)
    {
       long int pro=1;
        for(int i=0;i<n;i++)
        {
            pro=pro*2;
        }
        return pro;
    }
    int singleNumber(vector<int>& nums) {
        vector<int>ans(32,0);
        
        for(int i=0;i<nums.size();i++)
        {
            int j=0;
           long long int a=nums[i];
            if(nums[i]<0)
            {
                a=a&INT_MAX;
                long long int b=2147483648;
                a=a|b;
                
            }
            while(a)
            {
                ans[j]=ans[j]+(a&1);
                a=a>>1;
                j++;
            }
        }
        int sum=0;
        for(int i=0;i<32;i++)
        {
            // cout<<ans[i]<<" ";
            ans[i]=ans[i]%3;
            sum=sum+(ans[i]*power(i));
        }
        return sum;
    }
};