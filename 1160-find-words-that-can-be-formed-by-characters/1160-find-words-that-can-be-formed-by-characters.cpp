class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26,0);
        for(int i=0;i<chars.size();i++){
            freq[chars[i]-'a']++;
        }
        int sum=0;
        for(int i=0;i<words.size();i++){
            vector<int>temp=freq;
            for(int j=0;j<words[i].size();j++){
                if(temp[words[i][j]-'a']==0){
                    sum=sum-words[i].size();
                    break;
                }else{
                    temp[words[i][j]-'a']--;
                }
            }
            sum=sum+words[i].size();
            
        }
        return sum;
        
    }
};