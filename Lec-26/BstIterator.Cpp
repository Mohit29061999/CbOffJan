//problem link: https://leetcode.com/problems/binary-search-tree-iterator/#:~:text=Binary%20Search%20Tree%20Iterator%20%2D%20LeetCode&text=Implement%20the%20BSTIterator%20class%20that,binary%20search%20tree%20(BST)%3A&text=boolean%20hasNext()%20Returns%20true,the%20pointer%2C%20otherwise%20returns%20false%20.



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
class BSTIterator {
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode* root) {
        ///put the node which should be first in inorder traversal at top
        TreeNode* curr = root;
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        ///return the node at s.top()
        ///put the next value in the inorder traversal in stack
        TreeNode* curr= s.top();
        s.pop();
        int x=curr->val;
        ///next value at s.top() should be min value in right subtree
        curr = curr->right;
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        return x;
    }

    bool hasNext() {
        if(!s.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
