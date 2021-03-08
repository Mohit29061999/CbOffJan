#include <iostream>
using namespace std;

void towerOfHanoi(int n,char src,char help,char dest){
    //base case
    if(n==0)
        return;

//step1 :move n-1 disk from src to helping using destination
   towerOfHanoi(n-1,src,dest,help);
   //step 2:move nth disk from src to dest
   cout << "moving "<<n << " disk from " << src <<" " << dest << endl;

   //step3:move n-1 disk from helping to dest using src
   towerOfHanoi(n-1,help,src,dest);

}


int main(){
    char src='A';
    char help ='B';
    char dest='C';
  towerOfHanoi(3,src,help,dest);
}





