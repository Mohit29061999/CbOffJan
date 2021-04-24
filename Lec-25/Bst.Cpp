#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

///code for pre-order traversal (root,left subtree,right subtree)
void preOrder(Node* root){
    ///base case
    if(root==NULL)
        return;

    cout << root->val << " ";

    ///print the left subtree
    preOrder(root->left);

    ///print the right subtree
    preOrder(root->right);
}


///code for in-order traversal (left subtree,root,right subtree)
void inOrder(Node* root){
    ///base case
    if(root==NULL)
        return;


    ///print the left subtree
    inOrder(root->left);


    cout << root->val << " ";
    ///print the right subtree
    inOrder(root->right);
}

///code for post-order traversal (left subtree,right subtree,root)
void postOrder(Node* root){
    ///base case
    if(root==NULL)
        return;


    ///print the left subtree
    postOrder(root->left);
    ///print the right subtree
    postOrder(root->right);
    cout << root->val << " ";
}


///ek naya create karega in bst
Node* insertInBst(Node* root,int key){
    ///base case:if this node is NULL then create new node here
    if(root==NULL){
        root = new Node(key);
        return root;
    }

    ///if new node is to be created in left subtree
    if(root->val>key){
        root->left = insertInBst(root->left,key);
        return root;
    }
    else{
         ///if new node is to be created in right subtree
           root->right = insertInBst(root->right,key);
        return root;
    }

}

///to create the entire tree
Node*  createTree(){
    Node* root =NULL;
    int data;
    cin>>data;


    while(true){
    if(data==-1) //-1 means no new node has to be created
    break;
    root = insertInBst(root,data);
    cin>>data;
    }

    return root;


}



void levelOrderTraversal(Node* root){
    if(root==NULL)
    return;

    queue<Node*>q;
    q.push(root);

    ///while queue is non-empty,print the node present at the front and then insert its child in queue
    ///left then right
    while(!q.empty()){
        //print a level in one run
        int s=q.size();  ///number of nodes in current level
       for(int i=0;i<s;i++){
        Node* n =q.front();
         q.pop();
        cout << n->val << " ";

        ///check if left is not NULL then insert it
        if(n->left!=NULL){  ///when condition is not mentioned then it is assumed it is true
            q.push(n->left);  ///null means false , not NULL means true
        }

         ///check if right is not NULL then insert it
        if(n->right){
            q.push(n->right);
        }

       }
       cout << endl;
    }
}

int height(Node* root){
    if(root==NULL)
        return 0;



    ///get height of left subtree
    int l_height = height(root->left);

    ///get height of right subtree
    int r_height = height(root->right);

    return max(l_height,r_height)+1;  ///+1 for root

}





int main(){
Node* root =NULL;
root = createTree();
preOrder(root);

}

