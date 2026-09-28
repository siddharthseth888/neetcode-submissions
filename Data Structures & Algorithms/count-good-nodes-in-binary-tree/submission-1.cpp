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

class Solution {
public:
    void f(TreeNode* root, int& ans, int maxi)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->val >= maxi)
        {
            maxi = root->val;
            ans++;
        }
        f(root->left, ans, maxi);
        f(root->right, ans, maxi);

    }
    int goodNodes(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int maxi = INT_MIN;
        int ans = 0;
        f(root, ans, maxi);
        return ans;
    }
};
