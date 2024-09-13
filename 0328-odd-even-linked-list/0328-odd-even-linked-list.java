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
    public ListNode oddEvenList(ListNode head) {
        ListNode iterator = head;
        ListNode oddHead = new ListNode(-1,null);
        ListNode evenHead = new ListNode(-1,null);
        ListNode evenIterator= evenHead;
        int count =1;
        while(iterator != null){
            if((count&1)==1){
                oddHead.next = iterator;
                oddHead =oddHead.next;
            }else{
                evenIterator.next=iterator;
                evenIterator =evenIterator.next;
            }
            iterator= iterator.next;
            count++;
        }
        oddHead.next =evenHead.next;
        evenIterator.next =null;
        return head;
    }
}