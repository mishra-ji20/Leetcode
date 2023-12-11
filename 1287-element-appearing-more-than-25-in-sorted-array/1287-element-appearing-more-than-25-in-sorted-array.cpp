class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();){
            int cnt=0;
            int j=i;
            while(j<arr.size() && arr[i]==arr[j]){
                j++;
                cnt++;
            }
            // cout<<cnt<<" ";
            if(cnt>(arr.size()/4)){
                sum=sum+arr[i];
                
            }
            i=j;
        }
        return sum;
        
    }
};