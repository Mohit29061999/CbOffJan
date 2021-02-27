#include <iostream>
using namespace std;

int fact(int n){
    int ans =1;
    for(int i=1;i<=n;i++)
        ans=ans*i;
    return ans;
}

int nCr(int n,int r){
    int f1=fact(n); //n!
    int f2=fact(n-r);  //n-r!
    int f3=fact(r); //r!

    int ans = f1/(f2*f3);
    return ans;

}
int main(){
   int n,r;
   n=5;
   r=2;
  cout << nCr(n,r) << endl;
  cout << "We Are Done" << endl;

}

