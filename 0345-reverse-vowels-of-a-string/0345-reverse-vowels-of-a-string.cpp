class Solution {
public:
    bool checkVowel(char a) {
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='O'||a=='I'||a=='U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            // cout<<i<<" "<<j<<endl;
            while(i<j && (!checkVowel(s[i]))) {
                i++;
            }
            while(i<j && (!checkVowel(s[j]))) {
                j--;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
        
    }
};