///problem link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1#


#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        queue<pair<Node*,int>> q; ///to store horizontal distance and hd
        map<int,vector<int>>m;  ///for a hd , we can have multiple nodes

        ///insert root to queue as we are doing level order traversal
        q.push({root,0});
        while(!q.empty()){
            ///remove queue.front() from queue and insert its child in queue
            Node* curr = (q.front()).first;  ///node at front
            int hd = (q.front()).second ;  ///to hd of this node
            q.pop();

            if(m.find(hd)==m.end()){
                ///if this is first node with this hd
                ///then place empty vector in front of this hd in map
                vector<int> v;
                m[hd]=v;
            }

            m[hd].push_back(curr->data);  ///insert current node in the hd of current node

            ///insert the left child of this node
            if(curr->left){
                q.push({curr->left,hd-1});  ///hd(left child) = hd(parent) -1;
            }

            ///insert the right child of this node
            if(curr->right){
                q.push({curr->right,hd+1});  ///hd(right child) = hd(parent) +1;
            }

        }

        ///print all the nodes sorted ny hd value
        ///which is by default in map(not in unordered_map)
        vector<int>ans;
       // for(map<int,vector<int>>:: iterator it = m.begin();it!=m.end();it++ ){
       for(auto it = m.begin();it!=m.end();it++ ){
            ///find vector corresponding to this hd
            vector<int> v=it->second;
            ///print all the elements in this vector
            int s=v.size();
            for(int i=0;i<s;i++){
                ans.push_back(v[i]);
            }

        }

        return ans;

    }
};



// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);

    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends
