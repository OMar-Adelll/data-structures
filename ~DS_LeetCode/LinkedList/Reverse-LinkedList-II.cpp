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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode *h2 = head, *tail1 = nullptr;
        for (int i = 1; i < left; i++) {
            tail1 = h2;
            h2 = h2->next;
        }

        int len = right - left + 1;
        ListNode* h3 = h2;
        for (int i = 1; i <= len; i++)
            h3 = h3->next;

        ListNode* prv = nullptr;
        ListNode* cur = h2;
        for (int i = 0; i < len; i++) {
            ListNode* nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }
        // intervals now in reversed way is prv pointer
        // now the next step i will connect my list

        if (tail1)
            tail1->next = prv;
        else
            head = prv;

        h2->next = h3;

        return head;
    }
};
