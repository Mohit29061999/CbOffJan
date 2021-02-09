#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;

    //to print n rows we will use a lop
    for(int i=1;i<=n;i++){
        //current row ka test
        int x;
        if(i%2==1)
            x=1;
        else
            x=0;
        //loop to print row numbers in current row
        for(int j=1;j<=i;j++){
            cout << x << " ";
            x=1-x;
        }

        cout << endl;

    }

}


