class CustomStack {
    int[] stackArr;
    int[] marker ;
    int maxSize;
    int currIndex;
    public CustomStack(int maxSize) {
        stackArr = new int [maxSize];
        marker = new int [maxSize+1];
        this.maxSize = maxSize;
        currIndex = maxSize;
    }
    public void push(int x) {

        if(currIndex > 0){
            stackArr[--currIndex] = x;   
        }
        
//         System.out.print("Push    ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(stackArr[i]+" ");
//         }
//         System.out.print("         ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(marker[i]+" ");
//         }
        
//         System.out.println("     "+currIndex);
        
    }
    
    public int pop() {
        
    
        if(currIndex==maxSize){
            return -1;
        }
        int ans = stackArr[currIndex] +  marker[currIndex];
        marker[currIndex+1] +=marker[currIndex];
        marker[currIndex]=0;
        currIndex++;
        
        
//         System.out.print("Pop    ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(stackArr[i]+" ");
//         }
//         System.out.print("         ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(marker[i]+" ");
//         }
        
//         System.out.println("     "+currIndex);
        
        return ans;
        
        
        
    }
    
    public void increment(int k, int val) {
        if(currIndex > maxSize -k){
            marker[currIndex]+= val;
        }else{
            marker[maxSize-k]+=val;
        }
        
//         System.out.print("Increment    ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(stackArr[i]+" ");
//         }
//         System.out.print("         ");
//         for(int i=0;i<maxSize;i++){
//             System.out.print(marker[i]+" ");
//         }
        
//         System.out.println("     "+currIndex);
        
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */