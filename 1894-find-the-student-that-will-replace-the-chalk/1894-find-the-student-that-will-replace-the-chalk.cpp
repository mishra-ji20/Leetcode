class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long int sum=0;
        for(int i=0;i<chalk.size();i++)
        {
            sum=sum+chalk[i];
        }
        
        int a=k%sum;
        // cout<<a<<" ";
        int i=0;
        while(a>=chalk[i])
        {
            a=a-chalk[i];
            i=(i+1);
        }
        return i;
        
    }
};