#include <iostream>
#include <strings.h>
using namespace std;

int main(){
   // string s="";//empty string define kar rahe
    /*int n=4;
    for(int i=0;i<n;i++){
            char ch;
        cin>>ch;
        s+=ch;
    } */
    /*string s1="abcd";
    string s2="dcef";
    //s1+=' ';
    string s3=s1+s2;
    cout << s3 << endl;
      // cout << s << endl;
    //cin>>s;
   // s[0]='a'; //same as character array
    //cout << s << endl;
    */
    /*string s1="abc";
    string s2="a";
    if(s1<s2){ //dictonary order me compare karega
        cout << "Yes" << endl;
    }
    else
        cout << "NO" << endl; */

   /* string s="abbcjhdhjfjdf";
    int n=s.length();  //doesn't consider NULL
    cout << n << endl; */
    string s;
    getline(cin,s);  //getline works for string
    cout <<s << endl;
}
