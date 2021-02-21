#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max_sum=INT_MIN; //int ki min possible value
    int curr_sum=0;

    int c_s=0;  //current subarray ka starting point
    int max_l=0; //max subarray ki length
    int m_s=0;  //max subarray ka starting point
    for(int i=0;i<n;i++){
        //add current element to our subarray
        curr_sum+=a[i];
        //max_sum = max(max_sum,curr_sum);
        if(curr_sum>max_sum){
            //jo abhi starting point = max_subaraay ke starting
            //point ke
            m_s=c_s;
            max_l = i-c_s+1;
            max_sum = curr_sum;
        }
        //curr_sum<0
        if(curr_sum<0){
            //drop the current subarray ie.make it empty
            curr_sum=0;
            c_s=i+1;
        }
    }
    cout << max_sum << endl;
    for(int i=m_s;i<m_s+max_l;i++)
        cout << a[i] << " ";

}
