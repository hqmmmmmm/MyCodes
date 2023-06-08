/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 链表的中间结点 https://leetcode.cn/problems/middle-of-the-linked-list/
class Solution { // 先求出链表总的边数，再让头指针走 n/2+n%2(上取整)步
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        auto t = head;
        while(t->next) // 链表的边数
        {
            n++;
            t = t->next;
        }
        n = n / 2 + n % 2; // 走n / 2上取整

        while(n--) head = head->next;
        return head;
    }
};

class Solution {  // 快慢指针，快指针走两步，慢指针走一步，快指针到尾时，慢指针到中间
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        auto fast = head, slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};