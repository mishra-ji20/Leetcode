class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        set<int>st;
        unordered_map<int,int>mp;
        int i=0,j=1;
        int ma=0;
        int mi=0;
        long long sum=0;
        mp[nums[0]]++;
        st.insert(nums[0]);
        while(j<=nums.size()){
            ma=(*st.rbegin());
            mi=(*st.begin());
            // cout<<ma<<" "<<mi<<" ";
            if(ma-mi>2){
                mp[nums[i]]--;
                // cout<<mp[nums[i]]<<" ";
                if(mp[nums[i]]==0){
                    st.erase(nums[i]);
                }
                i++;
            }else{
                long long n=j-i;
                // cout<<n<<" ";
                sum+=n;
                if(j<nums.size()){
                st.insert(nums[j]);
                mp[nums[j]]++;
                }
                j++;
            }
            // cout<<endl;
        }
        return sum;
        
    }
};