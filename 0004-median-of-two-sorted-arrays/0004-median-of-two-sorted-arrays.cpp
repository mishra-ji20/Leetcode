class Solution {
public:
    int search(vector<int>nums,int t)
    {
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h)
        {
           int m=(l+h)/2;
            if(nums[m]<=t)
            {
                ans=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        // cout<<ans<<" ";
        return ans+1;
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        int m=nums1.size(),n=nums2.size();
        int a,b,c,d;
        a=m==0?INT_MAX:nums1[0];
        b=n==0?INT_MAX:nums2[0];
        c=m==0?INT_MIN:nums1[m-1];
        d=n==0?INT_MIN:nums2[n-1];    
        int l1=min(a,b);
        int h1=max(c,d);
        int l2=min(a,b);
        int h2=max(c,d);
        int k1,k2;
        if((m+n)%2==0)
        {
            k1=(m+n)/2;
            k2=(m+n)/2-1;
        }
        else{
            k1=(m+n)/2;
            k2=(m+n)/2;
        }
        // cout<<k1<<" "<<k2<<endl;
        int ans1;
        cout<<l1<<" "<<h1;
        while(l1<=h1)
        {
            int m=(l1+h1)/2;
            if(search(nums1,m)+search(nums2,m)>k1)
            {
                ans1=m;
                h1=m-1;
            }
            else
                l1=m+1;
        }
        int ans2;
        while(l2<=h2)
        {
            int m=(l2+h2)/2;
            if(search(nums1,m)+search(nums2,m)>k2)
            {
                ans2=m;
                h2=m-1;
            }
            else
                l2=m+1;
        }
        // cout<<ans1<<' '<<ans2<<" ";
        double x=double(ans1)+double(ans2);
        return x/2.0;
        
        
    }
};