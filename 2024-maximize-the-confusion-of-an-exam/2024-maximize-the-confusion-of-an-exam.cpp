class Solution {
public:
    int func(string str,int k , char ch1,char ch2){
         int i=0,j=0;
        int ans=0;
        int sum=0;
        while(j<str.size())
        {
            if(str[j]==ch1)
            {
                j++;
            }
            else{
                if(sum<k)
                {
                    sum++;
                    j++;
                }
                else{
                    if(str[i]==ch2)
                        sum--;
                    i++;
                    
                }
            }
            // cout<<j<<" "<<i<<endl;
            ans=max(ans,j-i);
            
        }
        return ans;
        
    }
    int maxConsecutiveAnswers(string str, int k) {
        int a=func(str,k,'T','F');
        int b=func(str,k,'F','T');
        return max(a,b);
    }
};