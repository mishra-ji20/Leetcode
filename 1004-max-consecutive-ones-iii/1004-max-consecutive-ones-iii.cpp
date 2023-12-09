class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==1){
                j++;
            }else if(k>0){
                j++;
                k--;
            }else{
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            ans=max(ans,j-i);
        }
        return ans;
        
    }
};