//请判断一个链表是否为回文链表。 
//
// 示例 1: 
//
// 输入: 1->2
//输出: false 
//
// 示例 2: 
//
// 输入: 1->2->2->1
//输出: true
// 
//
// 进阶： 
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？ 
// Related Topics 链表 双指针 
// 👍 939 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while (cur != NULL){
        struct ListNode* nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL){
        slow = slow->next;
    }
    struct ListNode* left = head;
    struct ListNode* right = reverse(slow);
    while (right != NULL){
        if (left->val != right->val){
            return 0;
        }
        left = left->next;
        right = right->next;
    }
    return 1;
}
//leetcode submit region end(Prohibit modification and deletion)
