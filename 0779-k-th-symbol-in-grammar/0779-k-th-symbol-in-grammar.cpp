class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        n--;
        vector<int>ans;
        if(n==0 || k==0)
            return 0;
        while(k) {
            ans.push_back(k&1);
            k=k/2;
        }
        for(int i=0;i<n;i++) {
            if(i>=ans.size()) {
                ans.push_back(0);
            }
        }
        reverse(ans.begin(),ans.end());
        int curr=0;
        for(int i=0;i<ans.size();i++) {
            if(ans[i]==1) {
                curr=(!curr);
            }
        }
        return curr;
        

    }
};