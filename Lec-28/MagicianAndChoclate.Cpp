//problem link: https://www.interviewbit.com/problems/magician-and-chocolates/

int mod =1000000007;

int Solution::nchoc(int A, vector<int> &B) {
   long long int ans=0;
   int n=B.size();

   priority_queue<int>pq; //max heap

   ///insert the choclates in all the bags in max heap
   for(int i=0;i<n;i++){
       pq.push(B[i]);
   }

   ///for A times,choose bag with max choclates currently and
   ///insert it floor(pq.top()/2) again in priority_queue
   while(A){
       ans+=(pq.top());
       int x=pq.top();

       ///insert x/2 in priority_queue after removing pq.top()
       pq.pop();
       pq.push(x/2);

       A--;
   }

   return ans%mod;

}
