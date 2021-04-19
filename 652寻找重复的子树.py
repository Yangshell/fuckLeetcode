# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        def findSubtrees(root: TreeNode) -> List[TreeNode]:
            listSubtrees = []
            if root == None:
                return []
            listSubtrees += findSubtrees(root.left)
            listSubtrees += findSubtrees(root.right)
            listSubtrees += [root]
            return listSubtrees
        def tree2str(root: TreeNode) -> str:
            return ''
        total_listSubtrees = findSubtrees(root)
        total_listStrSubtrees = [tree2str(x) for x in total_listSubtrees]
        total_listSetStrSubtrees = list(set(total_listStrSubtrees))
        listDuplicateSubtrees = []
        for i in total_listSetStrSubtrees:
            if total_listStrSubtrees.count(i) > 1:
        return total_listSetSubtrees
