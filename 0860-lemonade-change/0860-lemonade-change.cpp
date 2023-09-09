class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int collectedMoney=0;
        int dollar5=0;
        int dollar10=0;
        for(int i=0;i<bills.size();i++) {
           if(bills[i]==10){
               if(dollar5>0) {
                   dollar5--;
                   dollar10++;
               }else {
                   return false;
               }
           } else if(bills[i]==20) {
               if(dollar10>0 && dollar5>0) {
                   dollar10--;
                   dollar5--;
               } else if(dollar5>=3) {
                   dollar5-=3;
               } else {
                   return false;
               }
               
           } else {
               dollar5++;
           }
            
        }
        return true;
        
    }
};