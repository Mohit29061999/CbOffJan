#include <iostream>
using namespace std;

int power(int x,int y){
    //base case
    if(y==0)
        return 1;

         // if(y==1)
        //return x;

    //call simple problem
    int ans = power(x,y-1);
    return ans*x;
}


int main(){
    cout << power(2,3) << endl;
}

