#include <iostream>
using namespace std;




int main(){
   char a1[100];
   char a2[100];
   cin>>a1>>a2;

   int f1[26]={0};
   int f2[26]={0};
   //storing frequency of first string
   for(int i=0;a1[i]!='\0';i++){
       int x=a1[i]-'a';  //mapping from char to int
       f1[x]++;
   }

   //storing frequency of second string
   for(int i=0;a2[i]!='\0';i++){
       int x=a2[i]-'a';  //mapping from char to int
       f2[x]++;
   }

   //check count of every character in both strings
   //if they are equal for all then it is a permuation
   //else not
   bool isPermutation = true; //true means permutation
   for(int i=0;i<26;i++){
    if(f1[i]!=f2[i]){
        isPermutation =false;
        break;
    }
   }

   if(isPermutation==true)
    cout << "YES" << endl;
   else
    cout << "No" << endl;





}






