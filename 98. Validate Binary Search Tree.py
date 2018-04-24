# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        last = None
        def helper(root):
            nonlocal last
            if not root: return True
            if root.left and not helper(root.left): return False
            if last and last.val >= root.val: return False
            last = root
            if root.right and not helper(root.right): return False
            return True
        return helper(root)
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(root):
            cur, st, last = root, [], None
            while cur or st:
                while cur:
                    st.append(cur)
                    cur = cur.left
                cur = st.pop()
                if last and last.val >= cur.val:
                    return False
                last = cur
                cur = cur.right
            return True
        return helper(root)        
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(root):
            if not root: return (True, None, None)
            left = helper(root.left)
            right = helper(root.right)
            if not left[0] or not right[0]: return (False, None, None)
            if root.left and left[2].val >= root.val: return (False, None, None)
            if root.right and right[1].val <= root.val: return (False, None, None)
            maxT = right[2] if root.right else root
            minT = left[1] if root.left else root
            return (True, minT, maxT)
        return helper(root)[0]        
        
        