class Solution {
public:
    int countPrimes(int n) {
        vector<int>arr(n,0);
        if(n<=2)
            return 0;
        int count=1;
        for( long long int i=3;i<n;i=i+2)
        {
            if(arr[i]==0){
                count++;
            }
            for(long long int j=i*i;j<n;j=j+i)
            {
                arr[j]=1;
            }
        }
       return count;
        
    }
};