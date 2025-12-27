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
    pair<int, int> diameterOfTree(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto l = diameterOfTree(root->left);
        auto r = diameterOfTree(root->right);

        int h = 1 + max(l.second, r.second);

        int diameterOfRoot = l.second + r.second;
        int diameter = max({diameterOfRoot, l.first, r.first});

        return {diameter, h};
    }
    int diameterOfBinaryTree(TreeNode* root) { return diameterOfTree(root).first; }
};
