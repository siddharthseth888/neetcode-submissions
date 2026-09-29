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
    TreeNode* solve(int& idx, int start, int end, vector<int>& preorder, vector<int>& inorder)
    {
        if(start > end)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        int i;
        for(i = start; i <= end; i++)
        {
            if(inorder[i] == preorder[idx])
            {
                break;
            }
        }

        idx++;

        root->left = solve(idx, start, i-1, preorder, inorder);
        root->right = solve(idx, i+1, end, preorder, inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        return solve(idx, 0, n-1, preorder, inorder);
    }
};
