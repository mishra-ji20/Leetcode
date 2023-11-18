class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=nums.size()-1;
        int h=nums.size()-1;
        int ans=0;
        // cout<<nums.size()<<" ";
        
        int sum=k;
//         for(int i=12;i<86;i++){
//             sum=sum+nums[86]-nums[i];
            
//         }
//         cout<<sum<<endl;
        while(l>=0) {
            // cout<<nums[h]<<" "<<nums[l]<<" "<<k<<" "<<h-l<<" "<<h<<" "<<l<<" ";
            if(nums[h]-nums[l]<=k) {
                k=k-(nums[h]-nums[l]);
                l--;
                ans=max(ans,h-l);
                // cout<<"if"<<" ";
                
            }else {
                if(h-l>1){
                    k=k+(nums[h]-nums[h-1])*(h-l-1);
                }
                h--;
                // cout<<"else";
                
            }
            // cout<<endl;
        }
        return ans;
        
    }
};