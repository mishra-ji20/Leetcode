class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        sort(salary.begin(),salary.end());
        for(int i=1;i<salary.size()-1;i++)
        {
            ans=ans+salary[i];
        }
        return double(ans/(salary.size()-2));
        
    }
};