class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int prev1=1,prev2=1;
        int ans=1;
        for(int i=1;i<nums1.size();i++)
        { int a=0,b=0,c=0,d=0;
            if(nums1[i]>=nums1[i-1])
                a=prev1;
            if(nums1[i]>=nums2[i-1])
                b=prev2;
            if(nums2[i]>=nums1[i-1])
                c=prev1;
            if(nums2[i]>=nums2[i-1])
                d=prev2;
            prev1=max(a,b)+1;
            prev2=max(c,d)+1;
         ans=max(ans,max(prev1,prev2));
        }
        return ans;
        
    }
};