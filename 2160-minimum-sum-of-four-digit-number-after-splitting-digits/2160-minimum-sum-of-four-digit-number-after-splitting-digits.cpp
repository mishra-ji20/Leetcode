class Solution {
public:
    int minimumSum(int num) {
        vector<int>arr;
        while(num){
            arr.push_back(num%10);
            num=num/10;
        }
        sort(arr.begin(),arr.end());
        int x=(arr[3]+arr[2]);
        int y=(arr[0]+arr[1])*10;
        return x+y;
        
        
    }
};