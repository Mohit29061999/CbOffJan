#include <iostream>
#include <vector>
using namespace std;




int main(){

vector<int> v;
for(int i=0;i<10;i++)
    v.push_back(i+1);
v[0]=10;
v.pop_back();
for(int i=0;i<9;i++)
    cout << v[i] << endl;
cout << v.size() << endl;


cout <<v[0] << endl;

}


