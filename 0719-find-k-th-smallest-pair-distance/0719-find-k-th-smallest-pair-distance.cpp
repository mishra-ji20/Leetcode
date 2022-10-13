class Solution {
public:
    //MY priority_queue approach which failed
//     int smallestDistancePair(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         priority_queue<pair<int,pair<int,int>>>q;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             q.push({-abs(nums[i]-nums[i+1]),{i,i+1}});
//         }
//         int count=0;
//         int ans;
//         while(count<k)
//         {
//             auto a=q.top();
//             q.pop();
//             ans=-a.first;
//             // cout<<a.first<<" ";
//             if(a.second.second<nums.size()-1)
//             {
//                 q.push({-abs(nums[a.second.first]-nums[a.second.second+1]),{a.second.first,a.second.second+1}});
//             }
//             count++;
            
//         }
//         return ans;
        
        
//     }
     int smallestDistancePair(vector<int>& nums, int k) {
         int n=nums.size();
         sort(nums.begin(),nums.end());
         int l=0 ,h=nums[n-1]-nums[0];
         int ans;
         while(l<=h)
         {
             int m=(l+h)/2;
             if(check(nums,m,k)){
                 ans=m;
                 h=m-1;  
             }
             else
             l=m+1;
         }
         return ans;
          
     }
    bool check(vector<int>&nums,int m,int k)
    {
        int i=0;
        int j=i;
        int sum=0;
        while(j<nums.size())
        {
            while(j<nums.size() && nums[j]-nums[i]<=m)
            {
                j++;
            }
            while(i!=j && j<nums.size() && nums[j]-nums[i]>m)
            {
              sum+=j-i-1;
                i++;
            }
        }
        int a=j-i-1;
        sum=sum+(a*(a+1))/2;
        if(sum<k)
            return false;
        return true;
    }
};