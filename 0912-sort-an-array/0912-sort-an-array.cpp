class Solution {
public:
    void merge(int l,int mid,int h,vector<int>&arr)
    {
        int k=mid+1;
        vector<int>nums;
        int j=l;
        while(l<=mid && k<=h)
        {
            if(arr[l]<arr[k]){
                nums.push_back(arr[l]);
                l++;
            }
            else
            {
                nums.push_back(arr[k]);
                k++;
            }
            
        }
        while(l<=mid)
        {
           nums.push_back(arr[l]);
               l++;
        }
        while(k<=h)
        {
           nums.push_back(arr[k]);
               k++;
        }
        for(int i=0;i<nums.size();i++,j++)
        {
            // cout<<arr[j]<<" ";
            arr[j]=nums[i];
        }
        // cout<<endl;
    }
    void mergeSort(int l,int h,vector<int>&arr){
        if(l>=h)
            return;
        // cout<<l<<' '<<h<<"\n";
        mergeSort(l,((l+h)/2),arr);
        mergeSort(((l+h)/2)+1,h,arr);
        merge(l,(l+h)/2,h,arr);
    }
    vector<int> sortArray(vector<int>& nums) {
         mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};