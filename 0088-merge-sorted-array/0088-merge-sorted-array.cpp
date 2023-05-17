class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f=m-1,s=n-1;
        int i=m+n-1;
        while(f>=0 && s>=0)
        {
            if(nums1[f]>nums2[s])
            {
                nums1[i]=nums1[f];
                f--;
            }
            else
            {
                nums1[i]=nums2[s];
                s--;
            }
            i--;
        }
        while(s>=0)
        {
            nums1[i]=nums2[s];
            s--;
            i--;
        }
         while(f>=0)
        {
            nums1[i]=nums1[f];
            f--;
            i--;
        }
    }
        
};