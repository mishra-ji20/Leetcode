class Solution {
public:
    int search(vector<long int>&nums,int l,int h, long t)
    {
       // cout<<t<<" ";
        int ans=h+1;
        int a=h;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(nums[m]>t)
            {
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
                
        }
        // cout<<l<<" "<<h<<endl;
        // cout<<a+1-ans<<" ";
        // cout<<endl;
        return a+1-ans;
        
    }
    void merge(vector<long int>&nums,int l, int m,int h,int &res)
    {
        // cout<<l<<" "<<m<<" "<<h<<endl;
        vector<int>ans;
        for(int k=m+1;k<=h;k++)
        {
            long t =(long)(2)*nums[k];
            int a=search(nums,l,m,t);
            res=res+a;
        }
        int i,j;
        for( i=l,j=m+1;i<=m && j<=h;)
        {
            if(nums[i]<nums[j])
            {
                
                ans.push_back(nums[i]);
                i++;
            }
            else{
                
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m)
        {
            ans.push_back(nums[i]);
            i++;
        }
         while(j<=h)
        {
            ans.push_back(nums[j]);
            j++;
        }
        
        for(i=l,j=0;i<=h;i++,j++)
        {
            // cout<<ans[j]<<" ";
            nums[i]=ans[j];
        }
        // cout<<endl;
    }
    void divide(vector<long int>& nums,int i, int j, int &res)
    {
        if(i>=j)
            return;
        int m=(i+j)/2;
        divide(nums,i,m,res);
        divide(nums,m+1,j,res);
        merge(nums,i,m,j,res);
    }
    int reversePairs(vector<int>& nums) {
        int  res=0;
        vector<long int>arr;
        for(int i=0;i<nums.size();i++)
            arr.push_back(nums[i]);
        divide(arr,0,nums.size()-1,res);
        return res;
    }
};