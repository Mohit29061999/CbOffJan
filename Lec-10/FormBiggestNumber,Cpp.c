#include<iostream>
#include <algorithm>
using namespace std;

bool compare(string x,string y){
	string x_y=x+y; //first string pahle x ko place karo then y
	string y_x=y+x;  //second string then first ko place karo
	return x_y>y_x;
}
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;

		string arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n,compare);
		for(int i=0;i<n;i++)
		cout << arr[i];
		cout << endl;

	}

}
