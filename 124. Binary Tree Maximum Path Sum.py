# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        def help(root):
            if not root:
                return (-math.inf, -math.inf)
            left = help(root.left)
            right = help(root.right)
            one_path = max(0, left[0], right[0]) + root.val
            cross_sum = max(0, left[0]) + max(0, right[0]) + root.val
            cur_max = max(left[1], right[1], cross_sum)
            return (one_path, cur_max)
        return help(root)[1]
