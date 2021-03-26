#include <iostream>
#include <cstring>
using namespace std;

//this is just a blueprint
//this is just a datatype
class Student{
private:  //by default things are private in class
    int marks; //can't access this from outside of the class
public:
    static int count;
    //char name[100];
    char *name;
    //string name;
    int rollNo=0;
    float weight;

    //default constructor
    Student(){ //there is no return type of constructor
        count++;
       //rollNo++;
     cout << "default Constructor" << endl;

    }

    //getter function:to get value of a parivate variable
    int getMarks(){
        return marks;
    }

    //setter function:to set a private variable
    void setMarks(int m){
    marks =m;
    }

    //can have more than one constructor
    Student(char a1[100],float w,int r,int m){ //there is no return type of constructor
        count++;
        name =a1;  //talking about calling object only
        weight =w;
        rollNo = r;
        marks = m;
        cout << "Argument Constructor" << endl;
        rollNo++;
    }

    /*Student(float a2[100],float w,int r){ //there is no return type of constructor
        //name =a1;  //talking about calling object only
        weight =w;
        rollNo = r;
    } */

    //operator overloading
    //deep copying
    void operator=(Student x ){
       name = new char[100];
       //copy contents to new location
       strcpy(name,x.name);
       weight =x.weight;
       //rollNo = x.rollNo;
    }

    void print();  //prototype inside class to be defined outside

    //destructor ke case me no arguments are passed
    //so can only have one
    ~Student(){
        delete []name;
        name =NULL;
        cout << "Destructor" << endl;
    }
};

int Student::count =0;  //initalise a static variable
//define outside class
void Student::print(){
}

int main(){

Student s1;
cout << Student::count << endl;  //static variable belongs to class
//cout << s1.rollNo <<" "<<s2.rollNo << " " << s3.rollNo << endl;
Student s2;
cout << Student::count << endl;
Student s3;
cout << Student::count << endl;

cout << "destructor haven't called" << endl;
//destructor is called now
}





