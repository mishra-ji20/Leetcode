class Solution {
public:
    int maximumRobots(vector<int>& arr, vector<int>& nums, long long budget) {
        vector<long long int>sum;
        sum.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum.push_back(nums[i]+sum[i]);
        }
       long long  int ans=0;
        long long int i=0;
        set<pair<long long int,long long int>>st;
        for(long long int j=0;j<nums.size();)
        {
            if(st.empty()){
                st.insert({arr[j],j});
                j++;
            }
            while((st.rbegin()->first+ ((j-i)*(sum[j]-sum[i])))<=budget)
            {
                // cout<<st.rbegin()->first<<" ";
                ans=max(ans,j-i);
                if(j<nums.size())
                st.insert({arr[j],j});
                else
                {
                    break;
                }
                j++;
            }
             while(i!=j && i<nums.size() && !st.empty() &&(st.rbegin()->first+ ((j-i)*(sum[j]-sum[i])))>=budget)
            {
                
                st.erase({arr[i],i});
                  i++;  
            }
        }
        return ans;
        
        
    }
};