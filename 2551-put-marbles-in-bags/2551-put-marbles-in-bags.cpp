class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> pairVect;
        for(int i=0;i<weights.size()-1;i++)
        {
            pairVect.push_back(weights[i]+weights[i+1]);
        }
        sort(pairVect.begin(),pairVect.end());
        long long mi=0;
        long long ma=0;
        for(int i=0,j=pairVect.size()-1;i<k-1;i++,j--){
            mi+=pairVect[i];
            ma+=pairVect[j];
        }
        // cout<<mi<<" "<<ma;
        return ma-mi;
                                        
    }                                                                             
                                                                            
};