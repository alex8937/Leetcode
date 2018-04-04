class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        def findNext(left, st, cur):
            while cur:
                st.append(cur)
                cur = cur.left if left else cur.right
            cur = st.pop()
            val = cur.val
            cur = cur.right if left else cur.left
            return val, cur

        left_st, right_st = [], []
        left_val, left_cur = findNext(True, left_st, root)
        right_val, right_cur = findNext(False, right_st, root)
        while left_val < right_val:
            sum_val = left_val + right_val
            if sum_val > k:
                right_val, right_cur = findNext(False, right_st, right_cur)
            elif sum_val < k:
                left_val, left_cur = findNext(True, left_st, left_cur)
            else:
                return True
        return False
