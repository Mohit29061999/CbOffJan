///problem link: https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;

        ///mirror left subtree
        root->left = invertTree(root->left);

        ///mirror right subtree
        root->right = invertTree(root->right);

        ///swap left and right pointer
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;

    }
};
