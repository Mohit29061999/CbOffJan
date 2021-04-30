#include <iostream>
#include <vector>
using namespace std;



///to convert to max heap,just change comparison symbol ie. > to < and vice-versa

///when priority is not equal to value
///replace int by pair<int,int> ///p.first -> value and p->second -> priority
///for comparison , use p.second ie.v[i].second instead of v[i]
class minHeap{
public:
    vector<int>v;


    ///parent index = (i-1)/2 and left child = 2*i+1 and right child =2*i+2;
    minHeap(){

    }


    ///time complexity of inserting is O(h) as you go from last node to leaf while comparing parent
    /// in worst case where h is O(log(n)) in worst case
    void insert(int val){
        v.push_back(val);
        int i=v.size()-1;

        ///comapare new value with its parent and swap if neccessary

        while((i-1)/2>=0 && v[(i-1)/2]>v[i]){
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
    void minHeapify(int index){
        int smallest = index; ///assume parent is smallest value
        int l = index*2+1;   ///index of left child
        int r=index*2+2;  ///index of right child
         int n=v.size();
        if(l<n && v[index]>v[l]){
            smallest = l;
        }

        if(r<n && v[smallest]>v[r]){
            smallest = r;
        }

        ///if parent is not smallest
        if(index!=smallest){
                ///then swap parent with its smallest child
            swap(v[index],v[smallest]);
            minHeapify(smallest);
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
        minHeapify(0);
    }

};
int main(){
  minHeap h;
  h.insert(40);
   h.insert(30);
     h.insert(50);
   h.insert(-20);
     h.insert(100);
   h.insert(0);

   while(!h.empty()){
    cout << h.top() << " ";
    h.pop();
   }

}
