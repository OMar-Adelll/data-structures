/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int mxsum = INT_MIN, lv = 0, mxlv = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            lv++;
            int sum = 0, sz = q.size();
            while (sz--)
            {
                auto node = q.front();
                q.pop();
                sum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (sum > mxsum)
            {
                mxsum = sum;
                mxlv = lv;
            }
        }

        return mxlv;
    }
};
