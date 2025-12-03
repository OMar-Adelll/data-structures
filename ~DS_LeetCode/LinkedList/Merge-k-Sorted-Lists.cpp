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
    void addCorrect(ListNode*& dum, ListNode* node) {
        if (!dum || node->val <= dum->val) {
            node->next = dum;
            dum = node;
        } else {
            ListNode* trav = dum;
            while (trav->next && node->val > trav->next->val)
                trav = trav->next;

            node->next = trav->next;
            trav->next = node;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        ListNode* dummy = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            ListNode* head = lists[i];

            if (!head)
                continue;

            while (head) {
                ListNode* temp = head;
                head = head->next;
                temp->next = nullptr;
                addCorrect(dummy, temp);
            }
        }

        return dummy;
    }
};
