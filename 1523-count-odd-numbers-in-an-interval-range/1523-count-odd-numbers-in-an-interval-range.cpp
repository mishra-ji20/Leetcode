class Solution {
public:
    int countOdds(int low, int high) {
        int n=0;
        if(low%2==0) low++;
        if(high%2==0)high--;
        
        if(low<=high && low%2 && high%2)
        {
            n=((high-low)/2)+1;
        }
        return n;
       
        
    }
};