//problem link: https://leetcode.com/problems/sort-an-array/


///to convert to max heap,just change comparison symbol ie. > to < and vice-versa

///when priority is not equal to value
///replace int by pair<int,int> ///p.first -> value and p->second -> priority
///for comparison , use p.second ie.v[i].second instead of v[i]
class maxHeap{
public:
    vector<int>v;


    ///parent index = (i-1)/2 and left child = 2*i+1 and right child =2*i+2;
    maxHeap(){

    }


    ///time complexity of inserting is O(h) as you go from last node to leaf while comparing parent
    /// in worst case where h is O(log(n)) in worst case
    void insert(int val){
        v.push_back(val);
        int i=v.size()-1;

        ///comapare new value with its parent and swap if neccessary

        while((i-1)/2>=0 && v[(i-1)/2]<v[i]){
            ///swap current node and parent
            swap(v[i],v[(i-1)/2]);
            //check if parent index is also not valid
            i=(i-1)/2;
        }

    }

    ///return the element with highest priority
    ///here we are implementing a min heap so element with min value is having highest priority
    int top(){
        return v[0];
    }

    ///return no of elements in min heap
    int size(){
        return v.size();
    }

    ///tells if minHeap is empty or not
    bool empty(){
        return v.size()==0;
    }

    ///time complexity of pop function is O(h) in worst case
    ///since we start at root and we have to go till leaf node in worst case
    void maxHeapify(int index,int n){
        int smallest = index; ///assume parent is smallest value
        int l = index*2+1;   ///index of left child
        int r=index*2+2;  ///index of right child
         //int n=v.size();
        if(l<n && v[index]<v[l]){
            smallest = l;
        }

        if(r<n && v[smallest]<v[r]){
            smallest = r;
        }

        ///if parent is not smallest
        if(index!=smallest){
                ///then swap parent with its smallest child
            swap(v[index],v[smallest]);
            maxHeapify(smallest,n);
        }
    }

    ///remove the element with highest priority
    void pop(){
        if(v.size()==0){
            cout << "already empty" << endl;
            return;
        }
        ///swap first and last element
        swap(v[0],v[v.size()-1]);
        ///now remove the last element(which is actually first due to swapping)
        v.pop_back();
        maxHeapify(0,v.size());
    }

};




class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
         maxHeap h;
        int n=nums.size();

        ///insert all elements in max heap
        /// for this for loop time complexity is n*log(n); ///as insert has time complexity of log(n)
        for(int i=0;i<n;i++){
            h.insert(nums[i]);
        }

        ///one by one swap the root with last element and reduce the size of heap by 1
        ///we have to do this n-1 times

        ///it also has time complexity of n*logn
       /// n for for loop  and log for maxHeapify function
        for(int i=n-1;i>0;i--){
            ///swap 0th element and last element
            swap(h.v[0],h.v[i]); ///as 0 is max element of remaining heap (max heap)
            ///reduce the size of heap by 1 and call maxHeapify for root
            h.maxHeapify(0,i);
        }

        return h.v;

    }
};
