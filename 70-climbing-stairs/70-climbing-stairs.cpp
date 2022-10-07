class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2;
        int c=a+b;
        int d=2;
        while(d<n)
        {
            c=a+b;
            a=b;
            b=c;
            d++;
        }
        if(n==1)
            return a;
        else
            return b;
        
    }
};