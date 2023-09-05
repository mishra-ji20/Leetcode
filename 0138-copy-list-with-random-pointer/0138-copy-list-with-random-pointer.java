/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node,Node>mp=new HashMap<Node,Node>();
        Node dummyHead=new Node(-1);
        Node mainIterator=head;
        Node secondaryIterator=dummyHead;
        
        while(mainIterator!=null) {
            secondaryIterator.next=new Node(mainIterator.val);
            mp.put(mainIterator,secondaryIterator.next);
            mainIterator=mainIterator.next;
            secondaryIterator=secondaryIterator.next;
            
        }
        mainIterator=head;
        secondaryIterator=dummyHead.next;
        while(secondaryIterator!=null) {
            secondaryIterator.random=mp.get(mainIterator.random);
            secondaryIterator=secondaryIterator.next;
            mainIterator=mainIterator.next;
            
        }
        
        return dummyHead.next;
        
        
    }
}
