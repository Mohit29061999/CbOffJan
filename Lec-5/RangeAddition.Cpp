#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n]={0};
    int k;
    cin>>k;
    for(int i=0;i<k;i++){  //k ka loop
        int s_i,e_i,val;
        cin>>s_i>>e_i>>val;
        a[e_i]+=val;
        if(s_i!=0)
        a[s_i-1]-=val;
    }
    //add right contribution ie.not ending at that index
    //n ka loop
    for(int i=n-2;i>=0;i--)
        a[i]+=a[i+1];
    for(int i=0;i<n;i++)
        cout << a[i] << " ";







}




