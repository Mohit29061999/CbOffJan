#include <iostream>
using namespace std;

int main(){
 int n;
 cin>>n;

 for(int r=1;r<=n;r++){
    //task for rth row
    //print increasing char
    char ch='A';
    for(int i=1;i<=n-r+1;i++){
        cout << ch << " ";
        ch++;
    }

    //we stop at one value ahead so we do ch--;
    //for decreasing pattern
    ch--;  //ch is starting value for decreasing pattern
    for(int i=1;i<=n-r+1;i++){
        cout << ch << " ";
        ch--;
    }

    cout << endl;


 }


}





