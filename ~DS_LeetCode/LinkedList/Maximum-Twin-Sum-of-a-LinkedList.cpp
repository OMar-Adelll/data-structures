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
    int pairSum(ListNode* head) {

        ListNode *mid = head, *fast = head;
        while (fast->next && fast->next->next)
            fast = fast->next->next, mid = mid->next;

        ListNode *prv = nullptr, *cur = mid->next;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }


        ListNode* l = head;
        ListNode* r = prv;
        int M = 0;
        while (r) {
            M = max(M, l->val + r->val);
            l = l->next;
            r = r->next;
        }

        return M;
    }
};
