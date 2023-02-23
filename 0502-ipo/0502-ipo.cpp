class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       priority_queue<int>bucket;
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>q; 
        for(int i=0;i<profits.size();i++)
        {
            q.push({capital[i],profits[i]});
        }
        long long sum=w;
        while(k--)
        {
            while(!q.empty() && sum>=q.top().first){
                // cout<<q.top().first<<" ";
                bucket.push(q.top().second);
                q.pop();
            }
            ////////////cout<<endl;
            if(!bucket.empty()){
                // cout<<bucket.top()<<" ";
                sum+=bucket.top();
                bucket.pop();
            }  
        }
        return sum;
    }
};