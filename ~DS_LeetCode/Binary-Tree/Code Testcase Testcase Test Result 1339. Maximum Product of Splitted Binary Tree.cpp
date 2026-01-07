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
#define ll long long
#define Mod 1000000007

class Solution {
public:
    ll total, sub, ans;

    void totalSum(TreeNode* node) {
        if (!node)
            return;
        total += node->val;
        if (node->left)
            totalSum(node->left);
        if (node->right)
            totalSum(node->right);
    }

    ll dfs(TreeNode* node) {
        if (!node)
            return 0;

        ll lf = dfs(node->left);
        ll rt = dfs(node->right);

        ll sub = lf + rt + node->val;

        ans = max(ans, sub * (total - sub));

        return sub;
    }

    int maxProduct(TreeNode* root) {
        total = 0;
        sub = 0;
        ans = 0;

        totalSum(root);
        dfs(root);

        return ans % Mod;
    }
};
