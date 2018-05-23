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
        cur = head
        while cur:
            pre = cur
            while cur.next and cur.val == cur.next.val:
                cur = cur.next
            pre.next = cur.next
            cur = cur.next
        return head