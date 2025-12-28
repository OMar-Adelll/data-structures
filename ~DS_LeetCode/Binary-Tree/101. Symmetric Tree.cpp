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
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;

        if (!root1 || !root2)
            return false;

        if (root1->val != root2->val)
            return false;

        int o1 = dfs(root1->left, root2->right);
        int o2 = dfs(root1->right, root2->left);

        return o1 && o2;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        if (!root->left && !root->right)
            return true;

        if (!root->left || !root->right)
            return false;

        if (root->left->val != root->right->val)
            return false;

        return dfs(root->left, root->right);
    }
};
