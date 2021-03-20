#include <iostream>
#include <cstring>
using namespace std;

class Car{
public:
    char *name;
    int price;
    float model;

    Car(char *arr,int p,float m){
        name =arr;
        price=p;
        model = m;
    }

   /* Car(Car &C){
        //this is the code for default copy constructor
        //it is shallow copying
         name =C.name;
        price=C.price;
        model = C.model;

    } */


    Car(Car &C){

        //it is for deep  copying
        name = new char[100];
        strcpy(name,C.name);
         //name =C.name;
        price=C.price;
        model = C.model;

    }




};

int main(){
   char arr[100]="BMW";
  Car C(arr,100,0.5);

  Car B=C; //calling default copy constructor
 /* cout << B.price << endl;
  cout << B.model << endl;
  cout << B.name << endl; */
  B.name[0]='C';
  cout << C.name << endl;


}



