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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* left_subtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_subtree = lowestCommonAncestor(root->right, p, q);

        if((left_subtree == p && right_subtree == q) || (left_subtree == q && right_subtree == p))
        {
            return root;
        }

        if(left_subtree == NULL && right_subtree != NULL)
        {
            return right_subtree;
        }

        return left_subtree;
    }
};
