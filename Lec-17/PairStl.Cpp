#include <iostream>
#include <algorithm> //pair ki header file
using namespace std;


int main(){

pair<char,int>p={'a',4};
p.first ='a';
p.second = 4;
pair<char,int>p2={'b',5};
if(p<p2)
    cout << "pair p2 is greater" << endl;
else
    cout << "not" << endl;

cout << p.first << " " << p.second << endl;




}



