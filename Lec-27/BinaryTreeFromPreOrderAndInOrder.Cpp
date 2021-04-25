//problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
int index1=0; ///it will point to root of the tree to be created

///to find the index of root in inorder traversal
int find(vector<int> &in ,int val){
    int n= in.size();
    for(int i=0;i<n;i++){
        if(in[i]==val)
            return i;
    }
    return -1;
}
TreeNode* createTree(vector<int>&pre,vector<int>&in,int l,int r){
    if(l>r)
        return NULL;

    TreeNode* root = new TreeNode(pre[index1]);
    index1++; ///to consider next value as root next time

    ///find the index of root in inorder traversal
    int x=find(in,root->val);

    ///values from l to x-1 will be in left subtree
    root->left = createTree(pre,in,l,x-1);

     ///values from x+1 to r will be in right subtree
    root->right = createTree(pre,in,x+1,r);
    return root;


}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        index1=0;
        return createTree(preorder,inorder,0,n-1);
    }
};
