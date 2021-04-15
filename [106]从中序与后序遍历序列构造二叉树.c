//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组 
// 👍 485 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* build(int* inoder, int inStart, int inEnd, int* postorder, int postStart, int postEnd){
    if (inStart > inEnd){
        return NULL;
    }
    int index = 0;
    for (int i = inStart; i <= inEnd; i++){
        if (inoder[i] == postorder[postEnd]){
            index = i;
            break;
        }
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = postorder[postEnd];
    int postIndex = index - inStart;
    root -> left = build(inoder, inStart, index-1, postorder, postStart, postStart + postIndex - 1);
    root -> right = build(inoder, index + 1, inEnd, postorder, postStart + postIndex, postEnd - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
//leetcode submit region end(Prohibit modification and deletion)
