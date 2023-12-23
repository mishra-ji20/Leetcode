class Solution {
public:
    int subtract(string s1,string s2){
        // cout<<s1<<" "<<s2<<" ";
        string s1Hours=s1.substr(0,2);
        string s2Hours=s2.substr(0,2);
        string s1Minutes=s1.substr(3,2);
        string s2Minutes=s2.substr(3,2);
        long s1Hour=(s1Hours[0]-'0')*10+s1Hours[1]-'0';
        long s2Hour=(s2Hours[0]-'0')*10+s2Hours[1]-'0';
        long s1Minute=(s1Minutes[0]-'0')*10+s1Minutes[1]-'0';
        long s2Minute=(s2Minutes[0]-'0')*10+s2Minutes[1]-'0';
        int flag=0;
        int sum=0;
        int extra=0;
        if(s2Minute<s1Minute){
            extra=60;
            flag=1;
        }
        sum+=s2Minute+extra-s1Minute;
        // cout<<sum<<endl;
        sum+=(s2Hour-flag-s1Hour)*60;
        return sum;
        
    }
    bool comparator(string &s1, string & s2){
        for(int i=0;i<s1.size();i++){
            return s1[i]<s2[i];
        }
        return true;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int mi=INT_MAX;
        int n=timePoints.size()-1;
        for(int i=1;i<timePoints.size();i++){
            mi=min(mi,subtract(timePoints[i-1],timePoints[i]));
        }
        mi=min(subtract(timePoints[n],"24:00")+subtract("00:00",timePoints[0]),mi);
        return mi;
        
        
    }
};
