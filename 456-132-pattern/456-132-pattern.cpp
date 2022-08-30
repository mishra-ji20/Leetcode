class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        vector<int>res(nums.size(),0);
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res[i]=res[i-1]<nums[i]?res[i-1]:nums[i];
        }
        for(int j=nums.size()-1;j>=0;j--)
        {
            if(st.empty())
            {
                st.push(nums[j]);
            }
            else if(nums[j]!=res[j])
            {
                if(nums[j]<=st.top())
                {
                    st.push(nums[j]);
                }
                else{
                while(!st.empty() && res[j]>=st.top())
                {
                    st.pop();   
                }
                    if(st.empty())
                        st.push(nums[j]);
                    else
                        return true;
                }
            }
          
        }
        return false;
        
    }
};