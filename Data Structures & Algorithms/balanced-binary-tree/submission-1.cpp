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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left_height = 1 + height(root->left);
        int right_height = 1 + height(root->right);

        return max(left_height, right_height);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }

        int left_tree_height = height(root->left);
        int right_tree_height = height(root->right);

        if(abs(right_tree_height - left_tree_height) > 1)
        {
            return false;
        }

        bool left_subtree_balancing = isBalanced(root->left);
        bool right_subtree_balancing = isBalanced(root->right);

        return left_subtree_balancing && right_subtree_balancing;
    }
};
