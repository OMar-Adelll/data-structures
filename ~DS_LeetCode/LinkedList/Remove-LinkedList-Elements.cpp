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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;
        while (head && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *trav = head, *prv = nullptr;

        while (trav) {
            if (trav->val == val) {
                prv->next = trav->next;
                delete trav;
                trav = prv->next;
            } else {
                prv = trav;
                trav = trav->next;
            }
        }

        return head;
    }
};
