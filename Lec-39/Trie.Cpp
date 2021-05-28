#include <iostream>
using namespace std;

class TrieNode{
public:
    TrieNode* child[256];
    bool isEnd;

    TrieNode(){
        ///child =Null;
        for(int i=0;i<256;i++){
            child[i]=NULL;
        }

        ///currently it is not the ending of word
        isEnd =false;
    }
};

///to add a word in trie
void insert(TrieNode* root,string word){
    TrieNode* curr=root;

    int n=word.length();
    for(int i=0;i<n;i++){
        ///which child to look to
        int index= word[i];

       ///if node is not created then create it
       if(curr->child[index]==NULL){
          ///create it
           curr->child[index]=new TrieNode();
       }
       curr = curr->child[index];
    }

    ///since we are at a node which represent last char of a word
    curr->isEnd=true;

}


///search a particular word
bool search(TrieNode* root,string word){
    TrieNode* curr = root;
    int n=word.length();

    for(int i=0;i<n;i++){
        int index = word[i];

        ///check if index child exist or not
        if(curr->child[index]==NULL){
            ///as we don't have any word whose ith char equal to word[i]
            return false;
        }

        curr = curr->child[index];  ///now match next character
    }

    ///check if it is also last char of a word or not
    if(curr->isEnd==false)
        return false;

    return true;  ///word exist

}


int main(){
    TrieNode* root = new TrieNode();  ///act as dummy node

    insert(root,"abc");
    insert(root,"abcd");
    insert(root,"aefd");
    insert(root,"abcde");
    insert(root,"cde");
    insert(root,"cdfg");
    insert(root,"defh");
    insert(root,"abgi");

    string t;
    cin>>t;

    if(search(root,t)){
       cout << "word exist" << endl;}
       else
        cout << "word doesn't exist" << endl;


}
