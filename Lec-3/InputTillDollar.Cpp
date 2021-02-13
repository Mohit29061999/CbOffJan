#include <iostream>
using namespace std;

int main(){
 int count =0;
 char ch;
 //ch=cin.get();
 cin>>ch;

 while(ch!='$'){
    count++;
    //ch = cin.get();
    cin>>ch;

 }
   //cin ingnores white space while cin.get() don't
 cout << count << endl;


}






