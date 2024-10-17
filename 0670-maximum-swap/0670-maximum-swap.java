class Solution {
    public int maximumSwap(int num) {
        ArrayList<Integer> digits = new ArrayList<>();
        int numCopy = num ;
        while(numCopy>0){
            digits.add(numCopy%10);
            numCopy = numCopy/10;
        }
        boolean flag = true;
        for(int i = digits.size()-1; (i >= 0 ) ;i--){
            int maxIndex = i; 
            for(int  j = i-1;j>=0;j--){
                maxIndex = digits.get(maxIndex) <= digits.get(j)?j:maxIndex;
            }
            // System.out.println(digits.get(maxIndex));
            if(digits.get(maxIndex)>digits.get(i)){
                int temp = digits.get(maxIndex);
                digits.set(maxIndex,digits.get(i));
                digits.set(i,temp);
                break;
            }
        }
        int ans =0 ;
        for(int i=digits.size()-1 ;i>=0;i--){
            ans= (ans*10)+digits.get(i);
        }
        return ans;
        
    }
}