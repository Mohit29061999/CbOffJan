#include <iostream>
using namespace std;

template <typename T,typename T2>  //define a template t
class Pair{
public:
    T x;
    T2 y;

    Pair(T a,T2 b){
        x=a;
        y=b;
    }


    bool operator<(Pair<T,T2> p2){
        if(x<p2.x)
            return true;
        else if(x>p2.x)
            return false;

        return p2.y>y;
    }



};

int main(){
Pair<int,int> p1(4,5);
Pair<int,int> p2(4,6);

if(p1<(p2)==true){
    cout << "p2 is greater" << endl;
}
else
    cout << "p1 is greater" << endl;

//cout << p.x << " " << p.y << endl;




}


