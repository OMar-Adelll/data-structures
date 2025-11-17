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
    ListNode* nth_end(ListNode* head, int k) {
        int sz = 0;
        ListNode* trav = head;
        while (trav != nullptr)
            trav = trav->next, sz++;

        trav = head;
        sz = sz - k + 1;

        for (int i = 1; i < sz; i++)
            trav = trav->next;

        return trav;
    }
    ListNode* nth_begin(ListNode* head, int k) {
        ListNode* trav = head;
        for (int i = 1; i < k; i++)
            trav = trav->next;

        return trav;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* L = nth_begin(head, k);
        ListNode* R = nth_end(head, k);
        int temp = L->val;
        L->val = R->val;
        R->val = temp;

        return head;
    }
};