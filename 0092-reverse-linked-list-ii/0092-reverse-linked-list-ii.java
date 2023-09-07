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
    public ListNode reverse(ListNode head,ListNode tail) {
        ListNode curr=head;
        ListNode prev=tail;
        ListNode temp=head.next;
        
        while(curr!=tail) {
            curr.next=prev;
            prev=curr;
            curr=temp;
            if(temp!=null)
            temp=temp.next;
        }
        
        // while(curr!=tail) {
        //     System.out.print(temp.val+" ");
        //     temp=temp.next;
        // }
        return prev;
        
    }
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dh=new ListNode(-1,head);
        ListNode temp=dh;
        int cnt=0;
        ListNode temp1=dh;
        while(cnt<=right && temp!=null )
        {
            if(cnt<left-1) {
                temp=temp.next;
            }
            temp1=temp1.next;
            cnt++;
        }
        temp.next=reverse(temp.next,temp1);;
        return dh.next;
        
        
    }
}