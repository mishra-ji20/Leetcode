class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        for(int i=0;i<ast.size();i++)
        {
            bool flag=1;
            if(ast[i]<0){
                while(!(ans.empty()) && ans[ans.size()-1]>0){
                    if(ans[ans.size()-1]>abs(ast[i]))
                    {
                        flag=0;
                        break;
                    }
                    else if(ans[ans.size()-1]==abs(ast[i])){
                        flag=0;
                        ans.pop_back();
                        break;
                    }
                    else
                        ans.pop_back();
    
                }
            }
            if(flag)
                ans.push_back(ast[i]);
        }
        return ans;
        
        

        
        
    }

};