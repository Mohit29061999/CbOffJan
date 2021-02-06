
#include <iostream>
using namespace std;




int main(){

   int n;
   cin>>n;

   int x=0;  //it will tell us reversed number till now
   while(n>0){
    //it will get repeated
    int y=n%10;
    x=x*10+y;
   // cout<< y ;
    n=n/10;
   }

   cout << x << endl;

return 0;
}
