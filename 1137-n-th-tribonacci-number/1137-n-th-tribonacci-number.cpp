class Solution {
public:
    int tribonacci(int n) {
        int ans=n==0?0:1;
        if(n<3)
            return ans;
       int a=1;
       int b=1;
        int c=0;
        int temp=0;
        for(int i=3;i<=n;i++)
        {
            // cout<<a<<" "<<b<<" "<<" "<<c<<endl;
            temp=a+b+c;
            c=b;
            b=a;
            a=temp;
            
        }
        return temp;  
    }
};