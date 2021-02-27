#include <iostream>
using namespace std;

void update(int *a){
    *a=*a+1;
}
int main(){

   int n=5;
   update(&n);
   cout << n << endl;

}






