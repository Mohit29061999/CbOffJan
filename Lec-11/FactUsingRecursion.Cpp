#include <iostream>
using namespace std;

int fact(int n){

    //base case:simplest case
    if(n==0 || n==1)
        return 1;

        //fact(n) = fact(n-1)*n;
    //simple problem ko call kar rahe h
    int ans =fact(n-1);
    return ans*n;

}
int main(){
    cout << fact(5) << endl;
}
