class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveBillCollected = 0;
        int tenBillCollected =0;
        for(int index =0 ;index < bills.length ;index ++){
            if(bills[index]==5){
                fiveBillCollected++;
            }else if(bills [index] ==10){
                if(fiveBillCollected > 0){
                    tenBillCollected ++;
                    fiveBillCollected --;
                }else{
                    System.out.println(index +" " +"A");
                    return false;
                }
                
                
            }else{
                if(fiveBillCollected > 0 && tenBillCollected >0){
                    tenBillCollected --;
                    fiveBillCollected --;
                }else if(fiveBillCollected > 2){
                    fiveBillCollected -=3;
                }else{
                    System.out.println(index +" " +"B");
                    return false;
                }
            }
        }
        return true;
        
    }
}