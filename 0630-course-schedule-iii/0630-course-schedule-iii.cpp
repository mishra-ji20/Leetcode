class Solution {
public:

    static bool comp(vector<int>&a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        priority_queue<long>q;
        long long sum=0;
        int ans=0;
        for(int i=0;i<courses.size();i++){
            if(courses[i][0]<=courses[i][1]){
                sum=sum+courses[i][0];
                q.push(courses[i][0]);
                if(sum>courses[i][1]){
                    sum-=q.top();
                    q.pop();
                }
            }
 
        }
        return q.size();
        
    }
};