#include <iostream>
using namespace std;


int main(){
     int n;
     cin>>n;

     int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
     }

     for(int i=0;i<n-1;i++){
            bool swap=false; //false means no swap//true means swap done
        //in every iteration we go from
        //0 to n-2 and compare current index to next
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                //swap;
                swap = true;
                //a[j] =x;
                //a[j+1]=y;
                a[j]=a[j]+a[j+1]; //x=x+y;
                a[j+1] = a[j]-a[j+1];  //y=x-y;
                a[j] =a[j]-a[j+1]  ;     //x=x-y
            }
        }
        //check if swap is done or not
        if(swap==false){
            break;
        }

     }

     for(int i=0;i<n;i++)
        cout << a[i] << " ";
        //cout << 10 << endl; not part of loop


}

