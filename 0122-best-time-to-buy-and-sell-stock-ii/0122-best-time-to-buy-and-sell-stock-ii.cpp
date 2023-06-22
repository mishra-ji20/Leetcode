class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int curr=0,hold=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            curr=max(curr,hold+prices[i]);
            hold=max(hold,curr-prices[i]);
        }
        return curr;
    }
};