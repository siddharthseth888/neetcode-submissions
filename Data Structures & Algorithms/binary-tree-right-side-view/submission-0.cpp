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
    void f(TreeNode* root, int level, vector<int>& rightView)
    {
        if(root == NULL)
        {
            return;
        }
        if(level == rightView.size())
        {
            rightView.push_back(root->val);
        }
        f(root->right,level+1, rightView);
        f(root->left, level+1, rightView);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        int level = 0;
        vector<int> rightView;
        f(root, 0, rightView);
        return rightView;
        
    }
};
