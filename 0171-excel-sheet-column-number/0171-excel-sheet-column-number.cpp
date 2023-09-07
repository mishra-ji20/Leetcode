class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long sum=0;
        long long x=1;
        for(int i=columnTitle.size()-1;i>=0;i--) {
             sum=sum+((columnTitle[i]-'A'+1))*x;
             x=x*26;
        }
        return sum;
    }
};