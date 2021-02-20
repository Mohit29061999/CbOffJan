#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l[n],r[n];
    //left max for every bar
    l[0]=a[0];
    for(int i=1;i<n;i++){
        //l[i]=max of 0 to ith max = max of(0 to i-1,current_val)=max of(l[i-1],arr[i])
        l[i]=max(l[i-1],a[i]);
    }
    //storing right_max for every bar
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        r[i]=max(r[i+1],a[i]);
    }
    //finding water stored for every bar
    int ans =0;
    for(int i=0;i<n;i++){
        ans+=(min(l[i],r[i])-a[i]);
    }
   cout << ans << endl;


}

