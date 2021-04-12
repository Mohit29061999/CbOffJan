#include <iostream>
#include <stack>   ///include header file for stack
using namespace std;


int main(){
    string s;
    cin>>s;

    stack<char> s1;

    int n=s.length();

    bool ans = true;  ///it will tell us whether valid or not ,true means valid
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            //insert it to stack
            s1.push(s[i]);
            continue;
           }
        else if(s[i]==')'){
            if(s1.empty() || s1.top()!='('){
                ans = false;
                break;
               }

               s1.pop();
        }
         else if(s[i]==']'){
            if(s1.empty() || s1.top()!='['){
                ans = false;
                break;
               }

               s1.pop();
        }

        else if(s[i]=='}'){
            if(s1.empty() || s1.top()!='{'){
                ans = false;
                break;
               }

               s1.pop();
        }
    }

    if(ans==false || s1.size()>0){
        cout << "Invalid " << endl;
    }
    else
        cout << "Va
        lid " << endl;


}


