#include <iostream>
#include <algorithm> //inbuilt sort header file
using namespace std;
const int z=4;  //z should be constant to use it as
                //col in function

void fun(int arr[][z]){  //2-d array passed in function requires col
    cout << arr[0][0] << endl;
}
int main(){
   int arr[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
   //char arr[][4]={"abc","efg","ghi","kml"};
   int n=3;  //no of rows
   int m=4;  //no of cols
  /* for(int i=0;i<3;i++){
    for(int j=0;j<4;j++ )
        cin>>arr[i][j];
   } */

   /*for(int i=0;i<4;i++){
      for(int j=0;j<3;j++)
        cout << arr[i][j] << " ";

    cout << endl;
   }*/
   fun(arr);
}





