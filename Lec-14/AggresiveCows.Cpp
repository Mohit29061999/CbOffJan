#include<iostream>
#include <algorithm>
using namespace std;

bool canPossibleGreaterOrEqualToX(int arr[],int n,int c,int x){
	int cowPlaced=1;
	int lastPlacedLocation=arr[0];

	for(int i=1;i<n;i++){
		//kya new cow ko yaha place kar skte h???
		if(arr[i]-lastPlacedLocation>=x){
			//yes we can place
			cowPlaced++;
			lastPlacedLocation=arr[i];
		}
		else{
			//next position try karo
		}

	}

	//check if all cows are placed or not
	if(cowPlaced>=c)
	return true;
	return false;
}

int main() {
	int n;
	cin>>n;

	int c;
	cin>>c;

	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	sort(arr,arr+n);

	int min_d=1;
	int max_d=arr[n-1]-arr[0];
	int ans =0;
	while(min_d<=max_d){
		int mid_d=(min_d+max_d)/2;
		if(canPossibleGreaterOrEqualToX(arr,n,c,mid_d)==true){
			   //left half ko ignore karo
			   //ie. mid+1 to end
                  ans =mid_d;
				  min_d=mid_d+1;
		}
		else{
			//right half ko ignore karo
			max_d=mid_d-1;
		}
	}
	cout << ans << endl;
	return 0;
}
