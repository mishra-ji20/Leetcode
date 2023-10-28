class Solution {
public:
    int recur(vector<int>&num,int i,int sum,int tempSum, int start) {
        // cout<<i<<" "<<num.size()<<" akshat"<<endl;
        if(i>=num.size()){
            return sum;
        }
        int ans=0;
        for(int j=start;j<10;j++) {
            sum=sum*10+j;
            tempSum=(tempSum*10)+num[i];
            // cout<<sum<<" "<<tempSum<<endl;
            if(sum<=tempSum) {
                ans=max(ans,recur(num,i+1,sum,tempSum,j));
            }
            sum=sum/10;
            tempSum=tempSum/10;
            // cout<<sum<<" "<<tempSum<<endl;
        }
        return ans;
    }
    int monotoneIncreasingDigits(int n) {
        vector<int>num;
        while(n){
            num.push_back(n%10);
            n=n/10;
        }
        reverse(num.begin(),num.end());
        
        return recur(num,0,0,0,0);
        
    }
};