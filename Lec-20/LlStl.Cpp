#include <iostream>
#include <list>  //header file for ll stl
using namespace std;


int main(){
    list<int>l;  //create a ll from stl

    ///insert at start
    l.push_front(9);

    ///insert at end
    l.push_back(4);
    l.push_back(3);
    l.push_back(1);

    ///to print ll
    list<int>::iterator i;  ///address store karta h kissi class ke object ka
    ///used to traverse a ds

    for(i=l.begin();i!=l.end();i++)
        cout << *i << " ";
    cout << endl;
    ///delete from start
   // l.pop_front();

    ///delete from end
   // l.pop_back();

   /* for(i=l.begin();i!=l.end();i++)
        cout << *i << " ";
    cout << endl; */


    //l.sort();  ///to sort ll
     l.reverse();  ///to reverse a ll
    for(i=l.begin();i!=l.end();i++)
        cout << *i << " ";
    cout << endl;
  int n=l.size();  //number of nodes in ll
  cout << n << endl;



}
