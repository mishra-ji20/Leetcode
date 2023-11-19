class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        st.push(0);
        int i=1;
        vector<int>ans(heights.size(),0);
        while(!st.empty() && i<heights.size()){
            while(!st.empty() && heights[st.top()]<heights[i]){
                ans[st.top()]++;
                st.pop();
            }
            if(!st.empty())
                ans[st.top()]++;
            st.push(i);
            i++;
        }
        return ans;
        
    }
};