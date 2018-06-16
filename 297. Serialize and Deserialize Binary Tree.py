# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:


    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return '#'
        return str(root.val) + ' ' + self.serialize(root.left) + ' ' + self.serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nums = data.split()
        def helper(it):
            root = next(it)
            if root == '#':
                return None
            root = TreeNode(int(root))
            root.left = helper(it)
            root.right = helper(it)
            return root
        return helper(iter(nums))

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))