//problem link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>s1,s2;  ///s1 will act as left pointer and s2 will act as right pointer

        ///put the min value in the s1 stack intially
        TreeNode* curr = root;
        while(curr){
            s1.push(curr);
            curr=curr->left;
        }

          ///put the max value in the s2 stack intially
       curr = root;
        while(curr){
            s2.push(curr);
            curr=curr->right;
        }

        while(s1.top()!=s2.top()){
            TreeNode* c1=s1.top();
            TreeNode* c2=s2.top();

            if(c1->val + c2->val==k)
                return true;

            if(c1->val+ c2->val>k){
                s2.pop();
                ///r--;
                ///ie.remove the top value from s2 stack and insert the next
                ///max in stack
                c2=c2->left;
                while(c2){
                    s2.push(c2);
                    c2=c2->right;
                }
            }
            else{
                s1.pop();
                ///l++;
                 ///ie.remove the top value from s1 stack and insert the next
                ///min in stack
                c1=c1->right;
                while(c1){
                    s1.push(c1);
                    c1=c1->left;
                }
            }


        }

        return false;



    }
};
