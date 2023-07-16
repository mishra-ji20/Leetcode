class Solution {
public:
    void sol(vector<int>&ans,vector<vector<int>>&checker,int i,vector<int>&mp,vector<int> &res,int &val)
    {
        if(i>=checker.size())
        {

            if(ans.size()<val)
            {
                res=ans;
                val=ans.size();
            }
            return;
        }
        bool flag=0;
        for(int j=0;j<ans.size();j++)
        {
            if(checker[i][ans[j]])
            {
                flag=1;
                break;
            }
        }
        // cout<<i<<" "<<flag<<"\t";
        if(flag)
        {
            sol(ans,checker,i+1,mp,res,val);   
        }
        else
        {
            for(int j=0;j<checker[i].size();j++)
            {
                // cout<<checker[i][j]<<" ";
                if(checker[i][j])
                {
                    ans.push_back(j);
                    mp[j]=1;
                    sol(ans,checker,i+1,mp,res,val);
                    ans.pop_back();
                    mp[j]=0;
                }
                
            }
            // cout<<endl;
        }
            
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mp;
        for(int i=0;i<req_skills.size();i++)
        {
            mp[req_skills[i]]=i+1;
        }
        vector<vector<int>>checker(req_skills.size()+1,vector<int>(people.size(),0));
        for(int i=0;i<people.size();i++)
        {
            for(int j=0;j<people[i].size();j++)
            {
                checker[mp[people[i][j]]][i]=1;
            }
        }
        vector<int>ans;
        vector<int>res;
        vector<int>mp1(people.size(),0);
        int val=INT_MAX;
        sol(ans,checker,1,mp1,res,val);
        return res;
        
        
    }
};