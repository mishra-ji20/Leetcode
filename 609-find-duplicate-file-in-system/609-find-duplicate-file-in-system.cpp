class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string, vector<string>> mpsvv;
        for(int i=0; i<paths.size(); i++){
            string a = paths[i];
            string temp = "";
            int k = 0;
            while(a[k] != ' '){
                temp += a[k++];
            }
            k++;
            temp += '/';
            while(k < a.length()){
                string path = "";
                while(a[k] != '('){
                    path += a[k++];
                }
                k++;
                string content = "";
                while(a[k] != ')'){
                    content += a[k++];
                }
                k+=2;
                mpsvv[content].push_back(temp + path);
            }            
        }
        for(auto it : mpsvv){
            int sz = it.second.size();
            if(sz > 1){
                ans.push_back(it.second);
            }
        }
        return ans;
        
    }
};