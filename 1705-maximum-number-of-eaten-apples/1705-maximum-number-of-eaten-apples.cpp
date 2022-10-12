class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>>q;
        int dp=1;
        int ans=0;
        int i=1;
        q.push({-(days[0]),apples[0]});
          while(!q.empty())
          {
            while(!q.empty() && q.top().first+dp>0)
                q.pop();
            if(!q.empty())
            {
                auto a=q.top();
                q.pop();
                if(a.second>0)
                {
                    ans++;
                    if(a.second-1>0)
                    q.push({a.first,a.second-1});
                }
            }
              dp++;
              if(i<apples.size())
              {
                  q.push({-(i+days[i]),apples[i]});
                  i++;
              }
          }
        return ans;
        
        
    }
};