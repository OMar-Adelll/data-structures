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
    ListNode* sortList(ListNode* head) {
        ListNode* cur = head;
        vector<int> nums;
        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        int idx = 0;
        cur = head;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            cur->val = nums[idx++], cur = cur->next;

        return head;
    }
};
