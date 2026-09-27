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
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        {
            return true;
        }

        if((p == NULL && q != NULL) || (p != NULL && q == NULL))
        {
            return false;
        }

        if(p->val != q->val)
        {
            return false;
        }

        bool left_subtree = isSameTree(p->left, q->left);
        bool right_subtree = isSameTree(p->right, q->right);

        return left_subtree && right_subtree;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
        {
            return false;
        }

        if(subRoot == NULL)
        {
            return true;
        }

        if(isSameTree(root, subRoot))
        {
            return true;
        }

        bool left_part = isSubtree(root->left, subRoot);
        bool right_part = isSubtree(root->right, subRoot);
        return left_part || right_part;

    }
};
