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
    bool isPalindrome(ListNode* head) {
        if (not head || not head->next)
            return true;

        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* h2 = slow->next;
        slow->next = nullptr;

        // should make reverse to h2
        ListNode* rv = nullptr;
        while (h2 != nullptr) {
            ListNode* temp = h2->next;
            h2->next = rv;
            rv = h2;
            h2 = temp;
        }

        while (rv && head) {

            if (rv->val != head->val)
                return false;

            rv = rv->next;
            head = head->next;
        }

        return true;
    }
};