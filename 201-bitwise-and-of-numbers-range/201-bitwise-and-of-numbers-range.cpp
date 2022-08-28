class Solution {
public:
   long int power(int n)
    {
        long int pro=1;
        for(int i=0;i<n;i++)
        {
            pro*=2;
        }
        return pro;
    }
    int rangeBitwiseAnd(int left, int right) {
        if(left==0)
            return 0;
        int bc1=0;
        int bc2=0;
        long long int a=left,b=right;
        while(a)
        {
            bc1++;
            a=a>>1;
        }
        while(b)
        {
            bc2++;
            b=b>>1;
        }
        if(bc1!=bc2)
            return 0;
        bc1=min(bc1,bc2);
        int ans=INT_MAX;
        a=left>power(bc1-1)?left:power(bc1-1);
        b=right<power(bc1)-1?right:power(bc1)-1;
        while(a<=b)
        {
            ans=ans&a;
            a++;
        }
        return ans;
        
    }
};