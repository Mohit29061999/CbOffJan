//problem link: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
int maxPath(Node* root,int &res){
   ///for leaf node make it as starting point
  if(root->left==NULL && root->right==NULL){

    return root->data;
  }

    ///find the max value from left subtree in which
    ///root can be included
   if(root->left!=NULL && root->right!=NULL){
    int  l = maxPath(root->left,res);

    int  r= maxPath(root->right,res);

      res = max(res,root->data + r+l);

     int temp= INT_MIN;

      temp = max(temp,root->data+l);

    temp = max(temp,root->data+r);

    return temp;
   }

   ///it it has left child only
    if(root->left!=NULL && root->right==NULL){
    int  l = maxPath(root->left,res);

     int  temp = root->data+l;

    return temp;
   }

    ///it it has right child only
    if(root->left==NULL && root->right!=NULL){
    int  r = maxPath(root->right,res);
     int  temp = root->data+r;
    return temp;
   }
}
int maxPathSum(Node* root)
{ int res=INT_MIN;
if(root==NULL)
return 0;
maxPath(root,res);
return res;

}
