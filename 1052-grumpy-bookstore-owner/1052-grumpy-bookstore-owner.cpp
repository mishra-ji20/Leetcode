class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int notGrumpy=0;
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==1){
                grumpy[i]=customers[i];
            }else{
                notGrumpy+=customers[i];
            }
        }
        int extraCustomers=0;
        for(int i=0;i<minutes;i++){
            extraCustomers+=grumpy[i];
        }
        int temp=extraCustomers;
        for(int i=0,j=minutes;j<grumpy.size();i++,j++){
            temp=temp-grumpy[i];
            temp=temp+grumpy[j];
            extraCustomers=max(extraCustomers,temp);
        }
        return notGrumpy+extraCustomers;
        
    }
};