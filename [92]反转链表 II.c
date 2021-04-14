//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
// Related Topics 链表 
// 👍 864 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* successor = NULL;

struct  ListNode* reverseN(struct  ListNode* head, int right){
    if (head == NULL){
        return head;
    }
    if (head->next == NULL || right == 1){
        successor = head->next;
        return head;
    }
    struct ListNode* last = reverseN(head->next, right-1);
    head->next->next = head;
    head->next = successor;
    return last;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL || head->next == NULL){
        return head;
    }
    if (left == 1){
        return reverseN(head, right);
    }
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}
//leetcode submit region end(Prohibit modification and deletion)
