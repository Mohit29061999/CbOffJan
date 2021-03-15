#include <iostream>
using namespace std;

bool ratInAMaze(char arr[][5],int sol[][4],int i,int j,int n,int m)
{  //base case
    if(i==n-1 && j==m-1){
        if(arr[i][j]=='X')
            return false;
        sol[i][j]=1; //make destination cell part of solution
        ///cout << "sol exist" << endl;
        for(int k=0;k<4;k++){
            for(int w=0;w<4;w++)
                cout << sol[k][w] << " ";
            cout << endl;
        }
        cout << endl;
        return false;
    }

    sol[i][j]=1; //assume current cell is a part of solution

    //try right step
    if(j+1<m && arr[i][j+1]!='X'){
        //take right step
        bool kyaRightSePossible = ratInAMaze(arr,sol,i,j+1,n,m);
         if(kyaRightSePossible)
            return true;
    }

    //try down step
      if(i+1<n && arr[i+1][j]!='X'){
        //take right step
        bool kyaDownSePossible = ratInAMaze(arr,sol,i+1,j,n,m);
         if(kyaDownSePossible)
            return true;
    }
    sol[i][j]=0; //backtracking
    return false;

}
int main(){
    char arr[][5]={"OXOO","OOXO","OOOO","OOOO"};

    int sol[4][4]={0};

    if(ratInAMaze(arr,sol,0,0,4,4)==false)
        cout << "no Sol" << endl;
}
