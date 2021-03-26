#include <iostream>
using namespace std;

class Student{
    //by default private
    public:
        int marks;
        Student* setMarks(int marks){
            //always passed to function call
            //this a pointer that stores address of calling object
         // callingObject.marks = marks
         // (*this).marks =marks;  //object property marks = argument marks
        this->marks = marks;
        return this;
        }
};

int main(){
    Student s;

    Student* s1=s.setMarks(40);
    //whenever you have pointer to a object and uske through
    //object ki property access karni then we can use ->
    cout <<s1->marks << endl;
    cout << (*s1).marks << endl;



}
