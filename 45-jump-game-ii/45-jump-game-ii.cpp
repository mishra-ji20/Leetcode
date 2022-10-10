class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int ans=0;
        int hj=nums[0];
        int j;
        for(int i=0;i<nums.size();)
        {
            j=i;
            int temp=hj;
            while(j<hj)
            {
                j++;
                if(j>=nums.size()-1){
                    return ans+1;   
                } 
                if(nums[j]+j>temp)
                    temp=nums[j]+j;
            }
            if(j==nums.size())
                return ans;
            cout<<temp<<" ";
            ans++;
            hj=temp;
            i=j;
        }
        return ans;   
    }
};