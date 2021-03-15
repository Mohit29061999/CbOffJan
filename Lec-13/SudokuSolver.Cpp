#include <iostream>
using namespace std;

//0 means empty cell else it is not
bool emptyCell(int sudoku[][9],int &r,int &c){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                r=i;
                c=j;
              return true;
            }
        }
    }
    return false;
}

bool isSafe(int sudo[][9],int r,int c,int num){
    //check for current row if it have value num
    for(int i=0;i<9;i++){
        if(sudo[r][i]==num)
            return false;
    }

     //check for current col if it have value num
    for(int i=0;i<9;i++){
        if(sudo[i][c]==num)
            return false;
    }

    //check for 3*3 grid
    int r_s=r-r%3;
    int c_s=c-c%3;
    for(int i=r_s;i<r_s+3;i++){
        for(int j=c_s;j<c_s+3;j++){
            if(sudo[i][j]==num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int sudo[][9]){
    int r=-1;
    int c=-1;
    //base case
    if(emptyCell(sudo,r,c)==false)
    return true;

    //r and c are empty cell
    for(int i=1;i<=9;i++){ //try all numbers in current empty cell
        if(isSafe(sudo,r,c,i)==true){
            sudo[r][c]=i; //try i in this cell and check if sudoku
                          //can be solved with this value
            bool ans =solveSudoku(sudo); //fill rest cell
            if(ans ==true)
                return true;
            sudo[r][c]=0;  //backtrack and try new number at this position
        }
    }

    return false;




}


int main(){
  int sudo[9][9]={ { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

  solveSudoku(sudo);

  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
        cout << sudo[i][j] << " ";
    cout << endl;
  }



}


