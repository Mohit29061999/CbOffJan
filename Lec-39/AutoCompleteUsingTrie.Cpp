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
void printEveryWord(TrieNode* root,string curr){
    if(root==NULL)
        return;

    if(root->isEnd==true){
        cout << curr << endl;
    }

    curr+='.';
    for(int i=0;i<256;i++){
        if(root->child[i]!=NULL){
            curr[curr.length()-1]=i;
            printEveryWord(root->child[i],curr);
        }
    }
}
///print all suggestions
void printAll(TrieNode* root,string curr_string){
    ///base case
     if(root==NULL)
        return;

     ///if curr_string is a search term then print it
     if(root->isEnd==true){
        cout << curr_string << endl;
     }

     curr_string +='.'; ///it acts as a dummy value

        int n=curr_string.length();

     ///try all char as next char
     for(int i=0;i<256;i++){
        if(root->child[i]!=NULL){
            //cout << curr_string << " " << (char)i << endl;
            curr_string[n-1]=i;

            printAll(root->child[i],curr_string);
        }
     }


}


///give all suggestion for a search term
void autoComplete(TrieNode* root,string typed){
      int n=typed.length();
      TrieNode* curr= root;
      for(int i=0;i<n;i++){
           int index = typed[i];

           if(curr->child[index]==NULL)
            return;   ///no search term with the typed word

           curr=curr->child[index];
      }

      ///typed word exist in trie
      string curr_string = typed;
    //  cout << curr_string << endl;

     printAll(curr,curr_string);
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
    //printEveryWord(root,"");
    autoComplete(root,t);




}
