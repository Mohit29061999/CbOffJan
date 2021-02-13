#include <iostream>
using namespace std;



int main(){

  int count =0;
  int n;
  cin>>n;

  while(n!=0){
    //check if lsb is set or not
    if((n&1)>0)
        count++;  //count = count+1;
    n=(n>>1);
  }

  cout << count << endl;


}



