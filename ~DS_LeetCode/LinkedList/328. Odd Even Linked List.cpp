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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *ev = head->next, *odd = head, *cur = ev;
        while (ev && ev->next) {
            odd->next = ev->next;
            odd = odd->next;

            ev->next = odd->next;
            ev = ev->next;
        }
        odd->next = cur;
        return head;
    }
};
