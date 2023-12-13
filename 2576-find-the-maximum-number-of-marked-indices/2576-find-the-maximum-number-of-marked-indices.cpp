class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=(nums.size()-1)/2;
        int j=nums.size()-1;
        int i=mid;
        int ans=0;
        while(i>=0 && j>mid){
            if(nums[i]*2<=nums[j]){
                ans+=2;
                j--;
            }
            i--;
                
            
        }
        return ans;

        
    }
};