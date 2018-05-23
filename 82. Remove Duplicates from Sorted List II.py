# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        pre, cur = dummy, head
        while cur:
            while cur.next and cur.next.val == cur.val:
                cur = cur.next
            if pre.next != cur:
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        return dummy.next