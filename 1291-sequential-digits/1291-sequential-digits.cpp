class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int>q;
        for(int i=1;i<=9;i++)
        {
            q.push(i);
        }
        vector<int>res;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            if(a>=l && a<=h)
            {
                res.push_back(a);
            }
            // cout<<a<<" ";
            if(a>h)
                return res;
            int b=a%10;
            if(b+1<10)
            q.push((a*10)+(b+1));
        }
        return res;
    }
};