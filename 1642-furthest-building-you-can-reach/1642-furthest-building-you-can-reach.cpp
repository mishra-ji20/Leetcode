class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladder) {
        priority_queue<int>q;
        
        int i=0;
        int sum=0;
        for(i=0;i<h.size()-1;i++)
        {
           
            int a=h[i+1]-h[i];
             // cout<<i<<" "<<sum<<" "<<a<<"    ";
            if(a>0 && sum+a<=bricks){
                sum+=a;
                q.push(a);
            }
            else if(a>0 && sum+a>bricks)
            {
                if((q.empty() || a>q.top()) && ladder>0)
                {
                    // cout<<1<<" ";
                    ladder--;
                }
                else if(ladder>0)
                {
                    // cout<<2<<" ";
                    ladder--;
                    sum-=q.top();
                    q.pop();
                    sum=sum+a;
                    q.push(a);
                }
                else
                    break;
            }
            // cout<<3<<" ";
        }
       
        return i;
    }
};