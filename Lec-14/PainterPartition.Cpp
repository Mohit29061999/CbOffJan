#include <limits.h>
using namespace std;

bool canPossibleWithinX(int arr[],int n,int x,int k){
    int painterCount =1;
    int currentPainterTime=0;

    for(int i=0;i<n;i++){
        //kya current painter ko ye board de skte h???
        if(currentPainterTime+arr[i]<=x){
            //current painter ko ye waala board de do
            currentPainterTime+=arr[i];
        }
        else{
            //new painter is needed
            painterCount++;
             currentPainterTime=arr[i];
        }

    }

    if(painterCount>k)
    return false;
    return true;

}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int k;
	    cin>>k;

	    int n;
	    cin>>n;
	    int arr[n];
	    for(int j=0;j<n;j++)
	    cin>>arr[j];

	    int min_t=INT_MIN;
	    int max_t=0;
	       for(int j=0;j<n;j++){
	           min_t=max(min_t,arr[j]);
	           max_t+=arr[j];
	       }

	       int ans =-1;
	       while(min_t<=max_t){
	           int mid = (min_t+max_t)/2;
	           if(canPossibleWithinX(arr,n,mid,k)==true){
	               //ignore right value
	               ans = mid;
	               max_t=mid-1;
	           }
	           else{
	               //can't possible
	               //ignore left values
	               min_t=mid+1;
	           }
	       }

	       cout << ans << endl;

	}
	return 0;
}
