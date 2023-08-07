class Solution {
public:
    int getRowIndex(vector<vector<int>>& matrix,int a)
    {
        int i=0;
        int j=matrix.size()-1;
        while(i<=j)
        {
            cout<<i<<' '<<j<<endl;
            int mid=(i+j)/2;
            if(a<=matrix[mid][matrix[mid].size()-1] && a>=matrix[mid][0])
                return mid;
            else if(matrix[mid][0]>a)
                j=mid-1;
            else
                i=mid+1;
                
        }
        return -1;
    }
    bool getColumnIndex(vector<int>&matrix,int a)
    {
        int i=0;
        int j=matrix.size()-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(matrix[mid]==a)
                return true;
            else if(a>matrix[mid])
                i=mid+1;
            else 
                j=mid-1;
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a=getRowIndex(matrix,target);
        cout<<a<<' ';
        if(a!=-1)
        {
            return getColumnIndex(matrix[a],target);
        }
        return false;
        
    }
};