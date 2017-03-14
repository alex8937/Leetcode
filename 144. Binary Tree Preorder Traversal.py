# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans, stack, cur = list(), list(), root
        while cur or stack:
            while cur:
                stack.append(cur)
                ans.append(cur.val)
                cur = cur.left
            if stack:
                cur = stack.pop()
                cur = cur.right
        return ans
            