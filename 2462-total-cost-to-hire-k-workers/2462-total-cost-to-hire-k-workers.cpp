class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>q1,q2;
        int i=0;
        for(i=0;i<candidates;i++)
        {
            q1.push(costs[i]);
        }
        int j=costs.size()-1;
        int a=i>costs.size()-candidates?i:costs.size()-candidates;
        while(j>=a)
        {
            q2.push(costs[j]);
            j--;
        }
       
        i--;
        j++;
         // cout<<i<<" "<<j<<endl;
        long long sum=0;
        for(int counter=0;counter<k;counter++)
        {   
            
            if(q1.empty() || q2.empty())
            {
                // cout<<"x"<<endl;
                if(q1.empty()){
                    sum+=q2.top();
                    q2.pop();
                }else
                {
                    sum+=q1.top();
                    q1.pop();
                }
            }
           else if(q1.top()<=q2.top())
            {
                // cout<<"y"<<endl;
              sum+=q1.top();
                q1.pop();
                 i++;
                if(i<j){
                   
                    q1.push(costs[i]);  
                }
            }
            else{
                sum+=q2.top();
                // cout<<"z"<<endl;
                q2.pop();
                // cout<<q2.empty()<<" ";
                j--;
                if(i<j){
                    
                    q2.push(costs[j]);  
                }
                
            }
            // cout<<sum<<" ";
                
            
        }
        return sum;
        
    }
};