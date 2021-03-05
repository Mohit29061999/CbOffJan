//problem link : https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
      int n=A.length();
      
      //step1 : reverse every word
      int s=0; //word ka starting point
      for(int i=0;i<n;i++){//iterate for every character
          if(A[i]==' '){
              //reverse previous word
              int end =i-1;
              while(s<end){
                  //logic for swapping
                  char temp = A[end];
                  A[end]=A[s];
                  A[s]=temp;
                  
                  s++;
                  end--;
              }
              s=i+1;  //new word starts from next position
          }
          
      }
      
      
      //reverse last word
      int end =n-1;
      
        while(s<end){
                  //logic for swapping
                  char temp = A[end];
                  A[end]=A[s];
                  A[s]=temp;
                  
                  s++;
                  end--;
              }
      
      //step2:reverse string completely
      end =n-1;
      s=0;
      
      while(s<end){
           //logic for swapping
                  char temp = A[end];
                  A[end]=A[s];
                  A[s]=temp;
                  
                  s++;
                  end--;
      }
      
      string res="";
      //reduce starting space
      int i=0;
      while(i<n && A[i]==' ')
      i++;
      
      //reduce trailing space
      int j=n-1;
      while(j>=0 && A[j]==' ')
      j--;
      
      //reduce multiple space between ends
      while(i<=j){
          if(A[i]==' '){
              res+=' '; //to keep one space
              while(i<=j && A[i]==' ')
              i++;
          }
          else{
              res+=A[i];
              i++;
          }
      }
      
      return res;
      
      

}
