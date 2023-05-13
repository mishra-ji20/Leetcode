class Solution {
public:
    void func(vector<int> &nums,int a,int b)
    {
        for(int i=a;i<nums.size();i++)
        {
            if(b<nums.size()){
                nums[i]=nums[b];
                b++;
            }
            else
                nums[i]=INT_MAX;
            
        }
    }
    int removeDuplicates(vector<int>& nums) {
       int sum=0;
        for(int i=0;i<nums.size() && nums[i]!=INT_MAX;)
        {
            int a=nums[i];
            int j=i;
            while(j<nums.size() && a==nums[j])
            {
                j++;
            }
            // cout<<j-i<<" ";
            sum+=min(2,j-i);
            if(j-i>2)
            {
                func(nums,i+2,j);
            }
            
            if(j-i>=2)
                i=i+2;
            else
                i++;
        }
        // cout<<endl;
        return sum;
    }
};