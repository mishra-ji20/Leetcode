
class MyCircularDeque {
    
    
    class Node{
        int val;
        Node next;
        Node prev;
        public Node(int val ,Node prev, Node next){
            this.val = val;
            this.next = next; // This is a shallow copy 
            this.prev = prev;
        }
        public int getVal(){
            return val;
        }
        public Node getNext(){
            return next;
        }
        public Node getPrev(){
            return prev;
        }
        public void setNext(Node next){
            this.next = next;
        }
        public void setPrev(Node prev){
            this.prev = prev;
        }
        
        
    }
    
    int totalSize;
    int currSize;
    Node frontKeeper;
    Node backKeeper;
    public MyCircularDeque(int k) {
        totalSize = k;
        currSize = 0;
        frontKeeper = new Node (-1,null,null);
        backKeeper = new Node (-1,frontKeeper,null);
        frontKeeper.setNext(backKeeper);
    }
    
    public boolean insertFront(int value) {
        if(totalSize == currSize){
            return false;
        }else{
            Node newNode = new Node (value,frontKeeper,frontKeeper.getNext());
            frontKeeper.getNext().setPrev(newNode);
            frontKeeper.setNext(newNode);
            currSize++;
        }
        return true;
    }
    
    public boolean insertLast(int value) {
        if(totalSize == currSize){
            return false;
        }else{
            Node newNode = new Node (value,backKeeper.getPrev(),backKeeper);
            backKeeper.getPrev().setNext(newNode);
            backKeeper.setPrev(newNode);
            currSize++;
        }
        return true;
    }
    
    public boolean deleteFront() {
        if(currSize==0){
            return false;
        }else{
            frontKeeper.setNext(frontKeeper.getNext().getNext());
            frontKeeper.getNext().setPrev(frontKeeper);
            currSize--;
        }
        return true;
    }
    
    public boolean deleteLast() {
        if(currSize==0){
            return false;
        }else{
            backKeeper.setPrev(backKeeper.getPrev().getPrev());
            backKeeper.getPrev().setNext(backKeeper);
            currSize--;
        }
        return true;
        
    }
    
    public int getFront() {
        if(currSize==0){
            return -1;
        }else{
            return frontKeeper.getNext().getVal();
        }
        
    }
    
    public int getRear() {
        if(currSize==0){
            return -1;
        }else{
            return backKeeper.getPrev().getVal();
        }
        
    }
    
    public boolean isEmpty() {
        if(currSize==0){
            return true;
        }else{
            return false;
        }
        
    }
    
    public boolean isFull() {
        if(currSize==totalSize){
            return true;
        }else{
            return false;
        }
        
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */