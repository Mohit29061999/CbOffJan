#include <bits/stdc++.h> //add everything
using namespace std;

#define int long long int  //convert all int to long long int

int countdigit(int n){
    int c=0;
    while(n){
        n=n/10;
        c++;
    }
	return c;
}

int power(int x){
    int ans =1;
    for(int i=1;i<=x;i++)
        ans =ans*10;
    return ans;
}


bool compare(int  x,int y){
    int d1=countdigit(x);  //number of digits in x
    int d2=countdigit(y);   //number of digits in y
    int p1=power(d1);       //10^d1
    int p2=power(d2);       //10^d2
	int v1= x*p2+y;     //x+y
	int v2= y*p1+x;          //y+x
	return v1>v2;
}
int32_t main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;

		int  arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n,compare);
		for(int i=0;i<n;i++)
		cout << arr[i];
		cout << endl;
	}

}

