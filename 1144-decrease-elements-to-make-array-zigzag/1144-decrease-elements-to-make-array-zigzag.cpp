class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        vector<int>res(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            res[i]=nums[i];
        }
        int sum=0,sum1=0;
        for(int i=0;i<nums.size();i=i+2)
        {
            if(i>0 && nums[i-1]>=nums[i])
            {
              sum=sum+(nums[i-1]-nums[i])+1;
                nums[i-1]=nums[i]-1;
            }
            if(i<nums.size()-1 && nums[i+1]>=nums[i]){
                sum=sum+(nums[i+1]-nums[i])+1; 
                nums[i+1]=nums[i]-1;
            }
           
            // cout<<sum<<" "; 
        }
        
        for(int j=1;j<nums.size();j=j+2)
        {
             if(j>0 && res[j-1]>=res[j])
            {
              sum1=sum1+(res[j-1]-res[j])+1;
                res[j-1]=res[j]-1;
            }
            if(j<res.size()-1 && res[j+1]>=res[j]){
                sum1=sum1+(res[j+1]-res[j])+1; 
                res[j+1]=res[j]-1;
            }
            
        }
        // cout<<sum1<<' '<<sum;
        return min(sum,sum1);
        
        
    }
};