#include <iostream>
using namespace std;




int main(){
    int p,r,t;
    cin>>p>>r>>t;

    float si=(p*r*t)/100.0;

    //float si = (p*r*t)/100 gives only integer part
    cout << si << endl;


return 0;
}
