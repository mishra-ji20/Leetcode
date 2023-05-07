class Solution {
public:
    int search(vector<int> &arr,int num)
    {
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]>num)
                h=mid-1;
            else if(arr[mid]<=num)
                l=mid+1;
        }
        return l;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>heightLength;
        heightLength.push_back(obstacles[0]);
        vector<int>answer;
        answer.push_back(1);
        for(int i=1;i<obstacles.size();i++)
        {
            int l=search(heightLength,obstacles[i]);
            // cout<<l<<" ";
            if(l==heightLength.size())
                heightLength.push_back(obstacles[i]);
            else
                heightLength[l]=obstacles[i];
            // cout<<l<<" ";
            answer.push_back(l+1);
            
        }
        return answer;
    }
};