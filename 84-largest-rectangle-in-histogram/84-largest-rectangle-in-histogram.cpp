class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
       vector<int>left;
        vector<int>right;
        stack<int>st;
        for(int i=0;i<nums.size();i++)
        {
           while(!st.empty() && nums[st.top()]>=nums[i])
           {
               st.pop();
           }
            if(st.empty())
                left.push_back(-1);
            else
                left.push_back(st.top());
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=nums.size()-1;i>=0;i--)
        {
           while(!st.empty() && nums[st.top()]>=nums[i])
           {
               st.pop();
           }
            if(st.empty())
                right.push_back(nums.size());
            else
                right.push_back(st.top());
            st.push(i);
        }
        
        reverse(right.begin(),right.end());
         // for(int i=0;i<nums.size();i++)
             // cout<<left[i]<<" "<<right[i]<<"\n";
        int ma=INT_MIN;
        for(int i=0;i<left.size();i++)
        {
            int a=i-left[i]-1;
            int b=right[i]-i-1;
            ma=max(nums[i]*(a+b+1),ma);
            
        }
        return ma;
        
    }
};