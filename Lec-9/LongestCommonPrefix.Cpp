//problem link: https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
   int n=A.size();
   if(n==1)
   return A[0];
   string res="";
   
   //min length of all the strings
   int min_i=INT_MAX;
   for(int i=0;i<n;i++){
       int z=A[i].length();
   min_i=min(z,min_i);
   }
   
   for(int i=0;i<=min_i;i++){
       //whether current character is same in the all string
       char c=A[0][i];  //0th string ka ith character
       bool equal =true; // ith character is same in all the string
       for(int j=1;j<n;j++){
           if(A[j][i]!=c){
               equal =false;
               break;
           }
       }
       
       if(equal)
       res+=c;
       else
       break;
   }
   
   return res;
   
    
}
