class TreeNode:
    def __init__(self, val):
        self.val = val
        self.children = []
        
    def add_child(self, obj):
        self.children.append(obj)
        
    def __repr__(self):
        return self.repr_helper(0)

    def repr_helper(self, k):
        ans = ((' ' * k + '|-> ') if k > 0 else '') +  str(self.val) + '\n'
        for child in self.children:
            ans += child.repr_helper(k + 1)
        return ans
    __str__ = __repr__
    

def serealization(node):
    """
    >>> n1 = TreeNode(5)
    >>> n2 = TreeNode(6)
    >>> n3 = TreeNode(7)
    >>> n4 = TreeNode(8)
    >>> n5 = TreeNode(9)
    >>> n6 = TreeNode(10)
    >>> n7 = TreeNode(11)
    >>> n8 = TreeNode(12)
    >>> n1.add_child(n2)
    >>> n1.add_child(n3)
    >>> n1.add_child(n4)
    >>> n2.add_child(n5)
    >>> n2.add_child(n6)
    >>> n2.add_child(n7)
    >>> n4.add_child(n8)    
    >>> serealization(n1)
    '5 6 9 # 10 # 11 # # 7 # 8 12 # # #'
    """
    if not node:
        return ""
    root_str = str(node.val)
    if not node.children:
        return root_str + ' #'
    child_str = " ".join([serealization(child) for child in node.children])
    return "{} {} #".format(root_str, child_str)
  
def deserealization(data):
    """
    >>> data = '5 6 9 # 10 # 11 # # 7 # 8 12 # # #'
    >>> serealization(deserealization(data))
    '5 6 9 # 10 # 11 # # 7 # 8 12 # # #'
    """
    data_list = data.split()
    st = []
    for val in data_list:
        if val == '#':
            st.pop()
        else:
            cur = TreeNode(int(val))
            if not st:
                root = cur
            else:
                st[-1].add_child(cur)
            st.append(cur)
    return root
  
  

  
