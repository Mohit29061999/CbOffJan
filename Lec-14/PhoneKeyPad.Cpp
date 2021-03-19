#include <iostream>
using namespace std;

void phoneKeyPad(char a1[],string arr[],char out[],int i){
    //base case
    //already string is complete
    if(a1[i]=='\0'){
        out[i]='\0';
        cout << out << endl;
        return;
    }

    //get string corresponding to current digit
    string s=arr[a1[i]-'0'];  //a1[i] - '0' is done to get from '2' to 2

    //try every possible character for ith digit
    for(int j=0;j<s.length();j++){
        out[i]=s[j];
        //recursion will fix rest of the digit
        phoneKeyPad(a1,arr,out,i+1);
    }

}

int main(){
    //map digits to possible characters
    string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    char a1[100];
    cin>>a1;

    char out[100];

    phoneKeyPad(a1,arr,out,0);
}
