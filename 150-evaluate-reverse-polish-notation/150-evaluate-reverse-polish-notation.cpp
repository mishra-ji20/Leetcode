class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        st.push(stoi(tokens[0]));
        for(int i=1;i<tokens.size();i++)
        {
            if(tokens[i]=="+"){
                long b=(st.top());
                st.pop();
                long a=(st.top());
                st.pop();
                st.push((a+b));
            }
            else if(tokens[i]=="*"){
                 long b=(st.top());
                st.pop();
                long a=(st.top());
                st.pop();
                st.push((a*b));
            }
            else if(tokens[i]=="-")
            {
                long b=(st.top());
                st.pop();
                long a=(st.top());
                st.pop();
                st.push((a-b));
            }
            else if(tokens[i]=="/"){
                 long b=(st.top());
                st.pop();
                long a=(st.top());
                st.pop();
                st.push((a/b));
            }
            else
                st.push(stoi(tokens[i]));
        }
        
        return (st.top());
        
    }
};