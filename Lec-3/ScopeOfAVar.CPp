#include <iostream>
using namespace std;

int x=10;   //global variable
int main(){
   //int x=9;
   //x=9;
   //two variable with same name is allowed then there scope must be different
  if(true){

   int x=5;
   // int x=5;
  //x++;
   //cout << x << endl;
   cout << ::x << endl;  //local variable is prefered
  }
  x++;//here only x exist
cout << x << endl;
//{
   // int x=15;
//cout << x << endl;
//}

/*for(int i=0;i<10;i++){
   // cout << i << endl;
}  //i will point till this point
cout << i << endl; */
/*int i=0;
while(i<10){
        int y=5;
    cout << y << endl;
i++;
} */

//cout << i << endl;
//cout << y << endl;
// << x << endl;


}




