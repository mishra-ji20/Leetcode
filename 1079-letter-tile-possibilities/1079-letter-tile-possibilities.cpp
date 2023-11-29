class Solution {
public:
    int recur(char a,string ans, vector<int>&characters,int sum){
        ans.push_back(a);
        sum--;
        // cout<<a-'A'<<" ";
        characters[a-'A']--;
        // cout<<ans<<" ";
        int x=1;
        if(sum==0){
            characters[a-'A']++;
            return x;
        }
        for(int i=0;i<characters.size();i++){
            if(characters[i]!=0){
                x=x+recur(i+'A',ans,characters,sum);
                
            }
        }
        // cout<<endl;
        characters[a-'A']++;
        
        
        return x;
    }
    int numTilePossibilities(string tiles) {
        vector<int>characters(26,0);
        int sum=0;
        for(int i=0;i<tiles.size();i++) {
            characters[tiles[i]-'A']++;
        }
        sum=tiles.size();
        string ans;
        int x=0;
       
        for(int i=0;i<characters.size();i++){
            if(characters[i]!=0){
                x=x+recur(i+'A',ans,characters,sum);
            }
        }
        return x;
        
    }
};