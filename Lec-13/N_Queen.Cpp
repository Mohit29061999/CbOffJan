#include <iostream>
using namespace std;

//check if we can place queen at a cell
bool isSafe(int sol[][4],int r,int c,int n){
    //check for previous col
    for(int i=0;i<c;i++){
        if(sol[r][i]==1)
            return false;
    }

    //check for upper diagonal here both row-- and col--
    int c_r=r-1;
    int c_c=c-1;
    while(c_r>=0 && c_c>=0){
        if(sol[c_r][c_c]==1)
            return false;
        c_r--;
        c_c--;
    }

      //check for lower diagonal here row++ and col--
     c_r=r+1;
    c_c=c-1;
    while(c_r<n && c_c>=0){
        if(sol[c_r][c_c]==1)
            return false;
        c_r++;
        c_c--;
    }
    return true;
}

bool placeQueen(int c,int n,int sol[][4]){
    //base case
    if(c==n){
          for(int k=0;k<4;k++){
            for(int w=0;w<4;w++)
                cout << sol[k][w] << " ";
            cout << endl;
        }
        cout << endl;
        return false;
    }

    //try all rows in current col and place queen there
    for(int r=0;r<n;r++){
        if(isSafe(sol,r,c,n)==true){
        //place queen
        sol[r][c]=1;
        //next col me queen
        bool ans=placeQueen(c+1,n,sol);
        if(ans==true)
            return true;
        }

        //backtrack ie.different row
        sol[r][c]=0;
    }

    return false;
}

int main(){
  int sol[4][4]={0};
  placeQueen(0,4,sol);



}

