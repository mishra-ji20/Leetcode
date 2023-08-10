class Solution {
public:
    bool ser(vector<int>arr,int l,int r,int target)
    {
        int mid=(l+r)/2;
        if(arr[mid]==target)
            return true;
        if(l>=r)
            return false;
        
        
        if(arr[l]<arr[mid])
        {
           
            
            if(target>=arr[l] && target<=arr[mid]){
            return ser(arr,l,mid-1,target);}
            else{

                return ser(arr,mid+1,r,target);   
            }
        }
        else if(l!=mid && arr[l]==arr[mid] )
        {  
           
                return (ser(arr,l,mid-1,target)||ser(arr,mid+1,r,target));     
        }
        else{
           
             if(target>=arr[mid+1] && target<=arr[r]){
                  return ser(arr,mid+1,r,target);
             } 
            else {
                return ser(arr,l,mid-1,target);
            }
        }
        
        
    }
    bool search(vector<int>& nums, int target) {
        return ser(nums,0,nums.size()-1,target);
        
    }
};