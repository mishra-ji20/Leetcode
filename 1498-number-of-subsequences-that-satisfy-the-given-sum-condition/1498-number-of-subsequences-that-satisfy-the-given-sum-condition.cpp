class Solution {
public:
    int mod=1000000007;
    long long x=2;
    int pow(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int sum=0;
        while(i!=j)
        {
            // cout<<i<<" "<<j<<' ';
            if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else
            {
                sum=((sum)%mod+(pow(x,j-i,mod))%mod)%mod;
                i++;
            }
        }
        // cout<<i<<' ';
        if(nums[i]*2<=target)
            sum=(sum%mod+1)%mod;
        return sum;
        
    }
};