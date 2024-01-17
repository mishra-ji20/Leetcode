class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0,j=0;i<word1.size();){
            if(word1[i]!=word2[j]){
               return false; 
            }
            int it1=i;
            while(it1<word1.size() && word1[it1]==word1[i]){
                it1++;
            }
            int it2=j;
            while(it2<word1.size() && word2[it2]==word2[j]){
                it2++;
            }
            arr1.push_back(it1-i);
            arr2.push_back(it2-j);
            i=it1;
            j=it2;
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
        
        
    }
};