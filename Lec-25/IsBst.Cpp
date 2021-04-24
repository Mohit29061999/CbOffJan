#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node{
public:
    int val;
    Node* left;///left child ka address
    Node* right;   ///right child ka address

    Node(int v){
        val = v;
        left = NULL;
        right =NULL;
    }
};

Node* insert(){
    int data;
    cin>>data;

    if(data ==-1)  ///null child
        return NULL;

    ///create a new node
    Node* root = new Node(data);

    ///now create it's left subtree
    root->left = insert();
    ///right subtree
    root->right = insert();

    ///node,left subtree and right subtree is created so just return the tree
    return root;
}

///to print inOrder Traversal(left subtree,root,right subtree)
void inOrder(Node* root){
    if(root==NULL)
        return;
    ///print left subtree first
    inOrder(root->left);

    ///print root now
    cout << root->val << " ";

    ///print right subtree now
    inOrder(root->right);
}

///to print preOrder Traversal(root,left subtree,right subtree)
void preOrder(Node* root){
      if(root==NULL)
        return;

    ///print root now
    cout << root->val << " ";

    ///then left subtree first
    preOrder(root->left);

    ///print right subtree now
    preOrder(root->right);
}


///to print nodes level by level and from left to right
void levelOrderTraversal(Node* root){
    ///first method
    /*queue<Node*> q;
    q.push(root);
    while(!q.empty()){
            int s=q.size();
            ///print s nodes only that belong to this level and then print endl;
        for(int i=0;i<s;i++){
        ///take out the front node ,print it and insert it child's in queue
        Node* n =q.front();
        q.pop();

        cout << n->val << " ";

        ///insert left child of this node
        if(n->left){
            q.push(n->left);
        }

        if(n->right){
            q.push(n->right);
        }
        }
        cout << endl;
    } */

    ///second method
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  ///NULL means end of a level
    while(!q.empty()){

        ///take out the front node ,print it and insert it child's in queue
        Node* n =q.front();
        q.pop();

        if(n==NULL){
            if(!q.empty()){
                q.push(NULL);
                cout << endl;
            }
        }
        else{

        cout << n->val << " ";

        ///insert left child of this node
        if(n->left){
            q.push(n->left);
        }

        if(n->right){
            q.push(n->right);
        }
        }


}
}

Node* createTreeFromLevelInput(){
    Node* root =NULL;
    int data;
    cin>>data;
    ///to create tree with no node
    if(data==-1)
        return NULL;

    ///create root
    root = new Node(data);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        ///take out the front of queue and make its child
        Node* n =q.front();
        q.pop();

        ///ask the value of left child
        cin>>data;
        if(data!=-1){
            Node* newNode = new Node(data);
            n->left = newNode; ///make this as the left child
            q.push(newNode);
        }


           ///ask the value of right child
        cin>>data;
        if(data!=-1){
            Node* newNode = new Node(data);
            n->right = newNode; ///make this as the right child
            q.push(newNode);
        }

    }

    return root;
}

int height(Node* root){
    ///base case: if root is NUll then height =0;
    if(root==NULL){
        return 0;
    }

    ///calculate height of left subtree
    int l = height(root->left);

     ///calculate height of right subtree
    int r=height(root->right);

    return max(l,r)+1; ///1 for root

}

Node* search(Node* root,int key){
    if(root==NULL)
        return NULL;
    ///check if root is equal to key
    if(root->val ==key)
        return root;

    ///check in left subtree
    Node* l = search(root->left,key);

    ///l!=NUll means found in left subtree
    if(l!=NULL)
        return l;

    ///check in right subtree
    return search(root->right,key);

}

///tells if a binary tree is bst or not
bool isBst(Node* root,int min,int max){
    if(root ==NULL)
        return true;
    ///check if current node has value within range or not
    if(root->val<min || root->val>max)
        return false;

    /// check if left subtree is bst
    bool l = isBst(root->left,min,root->val);
    ///check if right subtree is bst
    bool  r= isBst(root->right,root->val,max);
    return l&&r;
}

int main(){
    Node* root =NULL;
   // root = insert();
   root = createTreeFromLevelInput();

   if(isBst(root,INT_MIN,INT_MAX))
    cout << "It is Bst" << endl;
   else
    cout << "No" << endl;


}

