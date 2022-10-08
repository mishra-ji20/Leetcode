class Solution {
public:
    void func(vector<int>&arr,string &res)
    {
        for(int i=0;i<arr.size();i++)
        {
            while(arr[i]>0)
            {
                res.push_back(i+'0'); 
                arr[i]--;
            }
        }
    }
    int nextGreaterElement(int n) {
        vector<int>arr(10,0);
        string res;
        string ans;
        int flag=0;
        while(n)
        {
            int a=n%10;
            arr[n%10]++;
             n/=10;
            for(int i=(a)+1;i<10;i++)
            {
                if(arr[i]>0)
                {
                    cout<<i<<" ";
                    flag=1;
                    arr[i]--;
                    res.push_back(i+'0');
                    func(arr,res);
                    break; 
                }
            }
            if(flag)
                break;
           
        }
        if(flag==0)
            return -1;
        while(n)
        {
            
            res=(char)((n%10)+'0')+res;
            n/=10;
        }
        long long num=0;
        for(int i=0;i<res.size();i++)
        {
            num=(long)(num*(long)10)+(long)res[i]-'0';
        }
        if(num>INT_MAX)
            return -1;
        return num;
    }
};