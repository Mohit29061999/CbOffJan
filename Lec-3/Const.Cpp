#include <iostream>
using namespace std;


int main(){
     const int x=10;   //value is must
    //x=10;  //error as value must be given while defining
   // x=5;  //constant so we can't change value

   int y=x+1; //valid as we are not changing constant here
   x=x+1;  //invalid as we are changing constant
}
