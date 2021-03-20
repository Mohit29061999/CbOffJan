#include <iostream>
using namespace std;

class Car{
private: //access within class
    int price;
public:
    char *name;
    float model;

    //getter function:private variable ki value return karta h
    int getPrice(){
        return price;  //jisne object ne call kiya usko price return karna h
    }

     //setter function:private variable ki value set karta h
    void setPrice(int x){
        if(x<=1000)
            return;
        price=x;  //jisne object ne call kiya usko price return karna h
    }



};

int main(){
 Car c;
// c.price=100;
 //cout << c.price << endl;

c.setPrice(100);  //sets value of a private variable
cout << c.getPrice() << endl; //gets value of a private variable

}



