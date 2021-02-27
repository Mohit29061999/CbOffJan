#include <iostream>
using namespace std;

void update1(int *p,int n){ //0th element ka address
     for(int i=0;i<5;i++){
      *(p+i)=*(p+i)+1;
   }
}

void update(int p[],int n){ //0th element ka address
     for(int i=0;i<5;i++){
     p[i]=p[i]+1;
   }
}
int main(){

   int arr[]={1,10,3,9,5};
  // int* p =arr;   //arr ka name = 0th element ka address
   //int* p =&(arr[0]);
  // for(int i=0;i<5;i++){
   //    cout << *(p+i) << " ";   //brackets are must as * has more precendce
   //}
   update(arr,5);
   for(int i=0;i<5;i++)
    cout << arr[i] << endl;

}







