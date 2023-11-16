class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<nums.size();i++) {
            int pro=1;
            int num=0;
            for(int j=nums.size()-1;j>=0;j--) {
                num+=(nums[i][j]-'0')*pro;
                pro=pro*2;
            }
            q.push(num);
            
        }
        int x=0;
        while(!q.empty()) {
            if(q.top()==x){
                x++;
            } else {
                break; 
            }
            q.pop();
        }
        string ans="";
        while(x)
        {
            ans.push_back((x&1)+'0');
            x=x>>1;
        }
        for(int i=ans.size();i<nums.size();i++)
        {
            ans.push_back('0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};