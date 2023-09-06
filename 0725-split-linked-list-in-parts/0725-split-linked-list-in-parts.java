/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int size=0;
        ListNode it=head;
        while(it!=null) {
            size++;
            it=it.next;
        }
        ListNode [] arr=new ListNode[k];
        int parts=size/k;
        int addOns=size%k;
        it=head;
        for(int i=0;i<k;i++) {
            arr[i]=it;
            int partSize=0;
            int totPartSize=parts+(addOns>0?1:0);
            addOns--;
            ListNode prev=null;
            while(it!=null && partSize<totPartSize) {
            
                prev=it;
                it=it.next;
                partSize++;
            }
            if(prev!=null)
                prev.next=null;
            
        }
        return arr;
        
        
    }
}