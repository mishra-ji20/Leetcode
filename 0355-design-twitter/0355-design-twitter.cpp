class Twitter {
public:

    int time;
    unordered_map<int,unordered_map<int,int>>following;
    unordered_map<int,vector<pair<int,int>>>post;
    Twitter() {
        time=1;
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({tweetId,time++}); 
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        res.push_back(userId);
        // cout<<"At!"<<endl;
        for(auto user:following[userId]){
            // cout<<user.first<<" "<<"InGetNewsFeed"<<endl;
                if(user.second==1){
                    res.push_back(user.first);
                }
        }
        // cout<<"akshat"<<endl;
        vector<int>iter(res.size(),0);
        vector<int>ans;
        for(int i=0;i<res.size();i++){
            iter[i]=post[res[i]].size()-1;
        }
        for(int i=0;i<10;i++){
            int mi=INT_MIN;
            int mi_iter=-1;
            int mi_Id;
            for(int j=0;j<res.size();j++){
                // cout<<post[res[j]][iter[j]].second<<endl;
                if(iter[j]>=0 && mi<post[res[j]][iter[j]].second){
                    mi=post[res[j]][iter[j]].second;
                    mi_Id=post[res[j]][iter[j]].first;
                    mi_iter=j;
                }
            }
            if(mi_iter!=-1){
                iter[mi_iter]--;
            }else{
                break;
            }
            ans.push_back(mi_Id);
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId][followeeId]=0;
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */