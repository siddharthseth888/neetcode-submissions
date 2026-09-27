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
    int f(TreeNode* root, int& max_length)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left_length = f(root->left, max_length);
        int right_length = f(root->right, max_length);

        max_length = max(max_length, left_length + right_length);

        return 1 + max(left_length, right_length);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_length = 0;
        f(root, max_length);
        return max_length;

    }
};
