class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& check, vector<int>& l, vector<int>& r) {
        vector<vector<int>>nums;
        for(int i=0;i<check.size();i++){
            nums.push_back({check[i],i});

        }
        sort(nums.begin(),nums.end());
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            int flag=0;
            int diff=-1;
            int prev=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j][1]>=l[i] && nums[j][1]<=r[i]){
                    // cout<<nums[j][0]<<' ';
                    if(flag>=2){
                        if(nums[j][0]-prev!=diff){
                            flag=-1;
                            break;
                        }
                    }
                    flag++;
                    diff=nums[j][0]-prev;
                    prev=nums[j][0];
                }
            }
            // cout<<endl;
            if(flag==-1)
                ans.push_back(false);
            else
            ans.push_back(true);
            
        }
        return ans;
    }

};