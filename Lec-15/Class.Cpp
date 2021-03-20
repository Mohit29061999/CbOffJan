#include <iostream>
using namespace std;

class Car{
public:
    char *name;
    int price;
    float model;

    //default constructor added by cpp
  /*  Car(int f){
    }

    Car(char *n,int f,float m){
        name = n;
        regNo=f;
        model = m;
    } */

};

int main(){
 char arr[100]="BMW";
 // Car c1;
  Car c(arr,10,0.5); //making object of a class constructor is called




 cout << c.name << endl;



}


