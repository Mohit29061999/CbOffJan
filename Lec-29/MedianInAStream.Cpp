//problem link: https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int>pq1; //max heap
    priority_queue<int,vector<int>,greater<int>>pq2; //min heap
    int turn;  ///to add in which priority queue
    int s;  ///to tell the number of elements in both the priority queue combined
public:
    /** initialize your data structure here. */
    MedianFinder() {

        s=0;
        turn =1; ///1 add the new element in max heap else add in min heap
    }

    void addNum(int num) {
        s++;
        if(turn==1){
            ///add the new element in max heap
            ///all the elements in max heap<=all the elements in min heap
            ///ie. to add the new element in max heap only if less than root of min heap
            if(!pq2.empty() && pq2.top()<num){
                ///can't insert the num in max heap as it should be less than minheap[0]
                ///so insert the new element in min heap and then shift its root to max  heap
                pq2.push(num);
                int x=pq2.top();
                pq2.pop();
                pq1.push(x);

            }
            else{
                pq1.push(num);
            }

            turn =0; ///next time insert it to min heap
        }
        else{
            ///add the new element to min heap
            ///add the new element to min heap only if it is greater than maxHeap[0]
            if(!pq1.empty() && pq1.top()>num){
                ///can't insert it to min heap
                ///insert the new number to max heap
                ///shift it max element to min heap
                pq1.push(num);
                int x=pq1.top();
                pq1.pop();
                pq2.push(x);

            }
            else{
                pq2.push(num);
            }

            turn =1;  ///next time insert to max heap

        }

        cout << pq1.top() << " ";
        if(!pq2.empty())
            cout << pq2.top() ;
        cout << endl;

    }

    double findMedian() {
        ///if total elements is even then median is avg of pq1.top() and pq2.top();
        ///else it is pq1.top();
        if(s%2==1){
            return pq1.top();
        }
        else{
           double ans = (pq1.top() +pq2.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
