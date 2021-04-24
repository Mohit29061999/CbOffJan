///problem link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/


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

class Info{
    public:
    bool isBst;
    int min_v;
    int max_v;
    int sum;

    Info(bool b,int f,int s,int t){
        isBst = b;
        min_v=f;
        max_v=s;
        sum =t;
    }


};

Info maxBst(TreeNode* root,int &res){
    if(root ==NULL){
       Info f(true,INT_MAX,INT_MIN,0);
        return f;
    }

    ///ask the data from left side
    Info l = maxBst(root->left,res);
    ///ask the data from right side
    Info r = maxBst(root->right,res);

    int min_v = min(root->val,min(l.min_v,r.min_v));
    int max_v = max(root->val,max(l.max_v,r.max_v));
    int sum = root->val + l.sum + r.sum;
    Info ret(true,min_v,max_v,sum);  ///assume total tree is bst
                                     ///it it not the case then we will change it

    ///check if left subtree is not bst or right subtree is not bst
    ///as then the entire tree will not be bst
    if(l.isBst==false || r.isBst == false){
        ret.isBst = false;
        return ret;
    }

    ///check if value of root> max value in left subtree and root<min value in right subtree
    if(root->val>l.max_v && root->val<r.min_v){
        ///check if this bst has a greater sum
        ///than previously stored value
        res = max(res,ret.sum);
        return ret;
    }
    ///else it is not bst
        ret.isBst = false;
        return ret;




}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int res=0;
        maxBst(root,res);
        return res;
    }
};
