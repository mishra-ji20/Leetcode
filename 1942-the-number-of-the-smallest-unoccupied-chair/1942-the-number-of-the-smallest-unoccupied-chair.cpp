class Solution {
public:
    static bool comp(vector<int>a,vector<int>b) {
        if(a[0]<b[0])
            return 1;
       return 0;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++) {
            times[i].push_back(i);
        }
        sort(times.begin(),times.end(),comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        priority_queue<int,vector<int>,greater<int>>chairs;
        int ma=0;
        chairs.push(0);
        for(int i=0;i<times.size();i++) {
            // cout<<times[i][0]<<" "<<times[i][1]<<" "<<times[i][2]<<"       ";
           while(!q.empty() && q.top().first<=times[i][0]) {
               // cout<<q.top().first<<' ';
               auto a=q.top();
               chairs.push(a.second);
               q.pop();
           }
            int chairAssigned=chairs.top();
            // cout<<chairs.top()<<' ';
            chairs.pop();
            if(times[i][2]==targetFriend)
                return chairAssigned;
            if(chairAssigned==ma){
                chairs.push(++ma);
            }
            
            q.push({times[i][1],chairAssigned});
            
        }
        return -1;

        
    }
};