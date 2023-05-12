class Solution {
public:
    void combination(vector<vector<int>>&ans,vector<int>temp,int counter, int &k ,int &n)
    {
        temp.push_back(counter);
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        for (int i=counter+1;i<=n;i++)
        {
            
            combination(ans,temp,i,k,n);
           
        }
            
    }
    vector<vector<int>> combine(int n, int k) {
        int counter=1;
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=1;i<=n;i++)
        combination(ans,temp,i,k,n);
        return ans;
        
    }
};