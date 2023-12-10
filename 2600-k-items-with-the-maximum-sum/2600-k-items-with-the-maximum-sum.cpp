class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum=0;
        sum+=min(numOnes,k);
        k=k-min(numOnes,k);
        if(k==0)return sum;
        k=k-min(numZeros,k);
        if(k==0)return sum;
        sum-=min(numNegOnes,k);
        return sum;
        
    }
};