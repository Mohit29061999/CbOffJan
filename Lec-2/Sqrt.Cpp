#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
int d;
cin>>d;
//cout << sqrt(n) << endl;
float ans =0;
float inc =1;
int c=0;
while(c<=d){
    while(ans*ans<=n){
        ans+=inc;
    }
    //we will stop one value ahead
    ans =ans-inc;
    c++;
    inc =inc/10;
}

cout << ans << endl;
}





