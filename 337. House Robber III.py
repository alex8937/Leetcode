# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(root):
            if not root:
                return (0, 0)
            left = helper(root.left)
            right = helper(root.right)
            yes = left[1] + right[1] + root.val
            no = max(left[0], left[1]) + max(right[0], right[1])
            return yes, no
        ans = helper(root)
        return max(ans)
            