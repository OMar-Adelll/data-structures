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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *cur = head, *t = head;
        while (cur)
            cur = cur->next, n++;

        if(n  == 0) return nullptr;

        k %= n;
        if (k > 0) {
            cur = head;
            while (k--)
                cur = cur->next;
            while (cur->next)
                cur = cur->next, t = t->next;

            cur = t->next;
            t->next = nullptr;

            ListNode* temp = cur;
            while (cur->next)
                cur = cur->next;

            cur->next = head;
            head = temp;
        }

        return head;
    }
};