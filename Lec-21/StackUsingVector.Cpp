#include <iostream>
#include <vector>
using namespace std;

class Stack{
private: ///by default things are private in class
    vector<int>v;
public:
    Stack(){
    }

    void push(int val){
        v.push_back(val);
    }

    void pop(){
        if(v.size()!=0)
        v.pop_back();
    }

    int size(){
        return v.size();
    }

    bool empty(){
        //return v.size()==0;
        if(v.size()==0)
            return true;
        else
            return false;
    }

    int top(){
        return v[v.size()-1];
    }



};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.size() << endl;
}
