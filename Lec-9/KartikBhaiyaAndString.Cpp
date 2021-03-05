//problem link: https://hack.codingblocks.com/app/contests/2116/446/problem


#include<iostream>
using namespace std;
int main() {
	int k;
	cin>>k;

	string s;
	cin>>s;

    int n=s.length();
	int ans =0;
	int st=0;
    int c=0;  //count of b

	//all a ie. k b allowed
	for(int i=0;i<n;i++){  //try every index as ending point of index
	//ith character is ending index
	     if(s[i]=='b'){
			 while(c==k){
				 if(s[st]=='b')
				 c--; 
				 st++; //move starting point one point ahead
			 }
			 //as new character is b and it is ending point of substring
			 c++;
		 }

		 ans =max(ans,i-st+1);

	}


		 st=0;
     c=0;  //count of b

	//all b ie. k a allowed
	for(int i=0;i<n;i++){  //try every index as ending point of index
	//ith character is ending index
	     if(s[i]=='a'){
			 while(c==k){
				 if(s[st]=='a')
				 c--; 
				 st++; //move starting point one point ahead
			 }
			 //as new character is b and it is ending point of substring
			 c++;
		 }

		 ans =max(ans,i-st+1);

	}
   
	cout << ans << endl;
	return 0;
}