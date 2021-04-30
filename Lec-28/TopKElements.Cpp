//problem link: https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1#


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to return k largest elements from an array.
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq; ///min heap
        ///insert first k elements in priority_queue
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }

        ///for rest of elements insert only if they are greater than pq.top()
        for(int i=k;i<n;i++){
            if(pq.top()<arr[i]){
                ///remove top element of priority_queue
                pq.pop();
                ///insert this new element
                pq.push(arr[i]);
            }
        }

        ///store top k elements in vector ans
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        ///elements are in increasing order in priority_queue as it is min heap
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;

    }
    return 0;
}
  // } Driver Code Ends
