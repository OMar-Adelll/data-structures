/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)
            return false;

        ListNode *sl = head, *fs = head;
        while (fs != NULL && fs->next != NULL) {
            fs = fs->next->next;
            sl = sl->next;

            if (fs == sl)
                return true;
        }
        return false;
    }
};