class Solution {
public:
    long long update(vector<long long> &segTree,int l,int r,int i,int curr)
    {
        if(curr>=segTree.size())
            return 0;
        if(l==i && r==i)
        {
            // cout<<l<<" "<<r<<endl;
            segTree[curr]+=1;
            return 1;
        }
        int mid=(l+r)/2;
        if(i>=l && i<=mid)
        {
            update(segTree,l,mid,i,2*curr+1);
        }
        else
            update(segTree,mid+1,r,i,2*curr+2);
        segTree[curr]++;
        return segTree[curr];   
    }
    void query(vector<long long> &segTree,int l, int r, int ql, int qr,int curr,long long &sum)
    {
        
        if(curr>=segTree.size())
            return;
        // cout<<ql<<" "<<qr<<" "<<endl;
        // cout<<l<<" "<<r<<" "<<segTree[curr]<<endl;
        if(l>=ql && r<=qr)
        {
            sum+=segTree[curr];
            return;
        }
        if(qr<l || r<ql)
            return;
        int mid=(l+r)/2;
        query(segTree,l,mid,ql,qr,2*curr+1,sum);
        query(segTree,mid+1,r,ql,qr,2*curr+2,sum);
        
    }
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<long long>segTree(4*nums.size()-1,0);
        vector<pair<int,int>>arr1;;
        for(int i=0;i<nums.size();i++)
        {
            arr1.push_back({nums[i],i});
        }
        sort(arr1.begin(),arr1.end());
        vector<int>arr;
        
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back(arr1[i].second);
        }
        vector<int>smallLeft(nums.size(),0);
        vector<int>smallRight(nums.size(),0);
        for(int i=0;i<arr.size();i++)
        {
            long long sum1=0,sum2=0;
            if(arr[i]-1>=0)
                query(segTree,0,nums.size()-1,0,arr[i]-1,0,sum1);
            // cout<<endl;
            if(arr[i]+1<nums.size())
                query(segTree,0,nums.size()-1,arr[i]+1,nums.size()-1,0,sum2);
            // cout<<endl;
            smallRight[arr[i]]=sum2;
            smallLeft[arr[i]]=sum1;
            update(segTree,0,nums.size()-1,arr[i],0);
            
        }
        // for(int i=0;i<smallLeft.size();i++)
        //     cout<<smallRight[i]<<" ";
        // cout<<endl;
        //  for(int i=0;i<smallLeft.size();i++)
        //     cout<<smallLeft[i]<<" ";
        // cout<<endl;
        
        int curr=0;
        long long sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=curr)
            {
               sum+=arr[i]-curr-(smallLeft[arr[i]]-smallLeft[curr]-1); 
            }
            else
                sum+=arr[i]+1-smallLeft[arr[i]]+nums.size()-1-curr-smallRight[curr];
            // cout<<sum<<" ";
            curr=arr[i];
        }
        // cout<<endl;
        return sum;
        
        
        
    }
};