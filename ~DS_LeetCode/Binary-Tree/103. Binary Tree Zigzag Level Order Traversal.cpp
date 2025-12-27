/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    bool make = 0;
    void zigzag(TreeNode* root) {
        if (!root)
            return;

        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {

            vector<int> row;
            int sz = level.size();

            while (sz--) {
                auto fr = level.front();
                level.pop();

                row.push_back(fr->val);

                if (fr->left)
                    level.push(fr->left);
                if (fr->right)
                    level.push(fr->right);
            }

            if (make)
                reverse(row.begin(), row.end());

            ans.push_back(row);
            make = !make;        
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzag(root);
        return ans;
    }
};
