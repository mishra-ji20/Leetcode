class Solution {
public:
    int countOrders(int n) {
        int MOD=1000000007;
        long long int arr[n+1];
        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            int a=((2*i)-1)%MOD;
            arr[i]=(((arr[i-1])%MOD)*(((a*(a+1))%MOD)/2)%MOD)%MOD;
        }
        return (int)arr[n];
        
    }
};