class Solution {
public:
   int sze(int n) {
    return log2(n) + 1;
}
    int concatenatedBinary(int n) {
        int mod=1e9+7;
        long long a=0;
        for(int i=1;i<=n;i++)
        {
            int b=sze(i);
            a=(a<<b)%mod;
            a=(a+i)%mod;
        }
        return a;
    }
};