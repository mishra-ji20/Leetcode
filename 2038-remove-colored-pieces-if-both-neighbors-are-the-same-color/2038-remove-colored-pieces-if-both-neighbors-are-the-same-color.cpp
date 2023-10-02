class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA=0,cntB=0;
        char prev=colors[0];
        for(int i=0;i<colors.size();) {
            int j=i;
            int tempA=0,tempB=0;
            while(j<colors.size() && prev==colors[j]) {
                if(prev=='A') {
                    tempA++;
                } else {
                    tempB++;
                }
                j++;
            }
            i=j;
            prev=colors[i];
            cntA+=tempA>2?tempA-2:0;
            cntB+=tempB>2?tempB-2:0;
        }
        if(cntA==0)
            return false;
        return cntA>cntB;
    }
};