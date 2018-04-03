# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        qu = collections.deque()
        table = collections.defaultdict(list)
        if root:
            qu.append((root, 1))
        while qu:
            head = qu.popleft()
            node, index = head[0], head[1]
            table[index].append(node.val)
            if node.left:
                qu.append((node.left, index - 1))
            if node.right:
                qu.append((node.right, index + 1))
        return [table[i] for i in sorted(table)]