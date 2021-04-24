//problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

int maxPath(TreeNode* root,int &res){
    ///base case: when node desn't exist then return 0
    if(root==NULL)
        return 0;

    ///find the max value from left subtree in which
    ///root can be included
    int l = maxPath(root->left,res);
    ///find the max value from right subtree in which
    ///root can be included
    int r= maxPath(root->right,res);
    ///case i : root alone
    res = max(res,root->val);

    ///case ii: root+ left subtree
      res = max(res,root->val + l);

        ///case iiI: root+right subtree
      res = max(res,root->val + r);

        ///case iv: root+right subtree+ left subtree
      res = max(res,root->val + r+l);

    ///return the value for the parent
    ///ie.max of first 3 cases
    int temp= root->val;
    temp = max(temp,root->val+l);
    temp = max(temp,root->val+r);

    return temp;



}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxPath(root,res);
        return res;
    }
};
