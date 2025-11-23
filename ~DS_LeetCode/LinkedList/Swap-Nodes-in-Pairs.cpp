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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;

        ListNode *cur = head;
        while(cur != nullptr)
        {
            int x = cur->val;
            if(cur->next == nullptr)
                break;
            cur->val = cur->next->val;
            cur->next->val = x;
            cur = cur->next->next;
        }

        return head;
    }
};