class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        int counter=0;
        for(int j=1;j<=k;)
        {
           if(counter<arr.size() && arr[counter]==i)
           {
               counter++;
           }
            else
               j++;
            i++;
        }
        return i-1;
    }
};