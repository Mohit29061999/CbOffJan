//problem link:https://leetcode.com/problems/balanced-binary-tree/

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

pair<bool,int> isBal(TreeNode* root){
    ///if root is NULL,h=0 and balanced = true
    if(root==NULL)
        return {true,0};

    ///ask the height and isBalanced from left subtree
    pair<bool,int> p1 =isBal(root->left);

     ///ask the height and isBalanced from right subtree
    pair<bool,int> p2 =isBal(root->right);

    ///current node height = max(h_left,h_right)+1;
    int h = max(p1.second,p2.second)+1;

    ///check if any of the left and right subtee is unbalanced
    if(p1.first==false || p2.first==false)
        return {false,h};
    ///if left subtree is balanced and right subtree is balanced then check for current
    ///node
    ///check if current node is balanced
    if(abs(p1.second - p2.second)<=1)
        return {true,h};
    else
        return {false,h};

}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        pair<bool,int> p= isBal(root);
        return p.first;
    }
};
