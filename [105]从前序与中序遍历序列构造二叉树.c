//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 987 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd){
    if (preStart > preEnd){
        return NULL;
    }
    int index = 0;
    for (int i = inStart; i <= inEnd; i++){
        if (inorder[i] == preorder[preStart]){
            index = i;
            break;
        }
    }
    int preIndex = index - inStart;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    root->left = build(preorder, preStart + 1, preStart + preIndex, inorder, inStart, index - 1);
    root->right = build(preorder, preStart + preIndex + 1, preEnd, inorder, index + 1, inEnd);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
//leetcode submit region end(Prohibit modification and deletion)
