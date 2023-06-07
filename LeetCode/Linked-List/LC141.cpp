/**     
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  // 环形链表 https://leetcode.cn/problems/linked-list-cycle/
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;  // 如果有环一定能检测出来
        }
        return false;  // 因为fast或fast的next指向了nullptr, 不存在环
    }
};