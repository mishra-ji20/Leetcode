class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        for(int i=0;i<deck.size();i++)
        {
            q.push(i);
        }
        sort(deck.begin(),deck.end());
        vector<int>ans(deck.size(),0);
        int i=0;
        while(!q.empty())
        {
            ans[q.front()]=deck[i];
            i++;
            q.pop();
            if(!q.empty()){
            q.push(q.front());
            q.pop();
            }
        }
        return ans;
    }
};