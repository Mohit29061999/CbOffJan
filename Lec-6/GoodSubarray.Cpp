#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    int start_sum[n];  //start_sum[i] = 0 to ith index
    start_sum[0]=a[0];
    for(int i=1;i<n;i++){
        start_sum[i]=start_sum[i-1] +a[i];
    }

    //take remainder for every index
     for(int i=0;i<n;i++){
        start_sum[i]= start_sum[i]%k;
    }
    //number of a times a remainder is coming
    int freq[k]={0};  //remainder possible 0 to k-1;
    for(int i=0;i<n;i++){
        freq[start_sum[i]]++;
    }
    //add contribution for every remainder
    int ans =freq[0];  //for 0 remainder,special case
    for(int i=0;i<k;i++){
            int x=freq[i];
        ans+=(x*(x-1)/2);
    }

    cout << ans << endl;




}

