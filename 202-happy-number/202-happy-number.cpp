class Solution {
public:
    bool isHappy(int num) {
        unordered_map<int,int>mp;
        int sum=num;
        while(mp[num]!=1)
        {
            mp[num]=1;
            int res=0;
            while(num>0)
            {
                int rem=num%10;
                res=res+rem*rem;
                num=num/10;
            }
            if(res==1)
                return true;
            else
                num=res;
        }
        return false;
        
    }
};