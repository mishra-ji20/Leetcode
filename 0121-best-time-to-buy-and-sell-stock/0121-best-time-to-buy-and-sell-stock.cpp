class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int bp=prices[0];
        if(prices.size()==0)
            return 0;
        int sp;
        for(int i=1;i<prices.size();i++)
        {
            sp=prices[i];
            if(sp-bp>max)
            {
                max=sp-bp;
            }
            else if(sp<bp)
                   bp=sp;
        }
        return max;
        
    }
};