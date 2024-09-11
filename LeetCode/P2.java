/*
    * Problem: 2. Add Two Numbers
    * Source: https://leetcode.com/problems/add-two-numbers/
*/

/*
    Definition for singly-linked list.
    public class ListNode
    {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
 */

public class P2
{
    public static void main(String[] args)
    {
        ListNode l1 = new ListNode(2);
        l1.next = new ListNode(4);
        l1.next.next = new ListNode(3);

        ListNode l2 = new ListNode(5);
        l2.next = new ListNode(6);
        l2.next.next = new ListNode(4);

        ListNode result = addTwoNumbers(l1, l2);
        while (result != null) {
            System.out.print(result.val + " ");
            result = result.next;
        }
    }

    public static class ListNode
    {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val)
        {
            this.val = val;
        }
        ListNode(int val, ListNode next)
        {
            this.val = val; this.next = next;
        }
    }
    
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode result = new ListNode();
        ListNode current = result;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            if (l1 != null) {
            carry += l1.val;
            l1 = l1.next;
            }
            if (l2 != null) {
            carry += l2.val;
            l2 = l2.next;
            }
            current.next = new ListNode(carry % 10);
            carry /= 10;
            current = current.next;
        }

        return result.next;
    }
}
