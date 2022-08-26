class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       vector<int>res;
        for(int i=0;i<gas.size();i++)
        {
            res.push_back(gas[i]-cost[i]);
        }
        int cur_sum=res[0];
        int sum=0;
        int start=0;
        for(int i=1;i<res.size();i++)
        {
            if(cur_sum<0 && res[i]>0)
            {
                start=i;
                sum=sum+cur_sum;
                cur_sum=res[i];
            }
           else
               cur_sum=cur_sum+res[i];
        }
        if(sum+cur_sum>=0)
            return start;
        else
            return -1;
        
    }
};