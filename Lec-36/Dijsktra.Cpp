#include <iostream>
#include <vector>
#include <queue>     ///header file for queue and p_queue
#include <utility>  ///header file for pair
#include <limits.h>  ///for INT_MAX and INT_MIN
using namespace std;

class edge{
    public:
    int dest;
    int weight;


};

class Graph{
    private:
    vector<vector<edge>>v;  ///adjacency list
    int n;  ///number of vertex in graph


    public:
        Graph(int v1){
            n=v1;
            ///my graph is empty now
            for(int i=0;i<n;i++){
                vector<edge>temp;
                v.push_back(temp);
            }
        }

        void addEdge(int x,int y,int wt,bool bidir=true){
            ///connect edge between x and y
            edge e;
            e.dest=y;
            e.weight = wt;
            v[x].push_back(e);
            if(bidir){
                e.dest = x;
                v[y].push_back(e);
            }
        }


         int dijkstra(int s,int d){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ; ///min heap

                  int dist[n];
                  for(int i=0;i<n;i++){
                    dist[i]=INT_MAX;
                  }

                  dist[s]=0;
                  pq.push({0,s});  ///dist first and then vertex

                  while(!pq.empty()){
                       pair<int,int>p=pq.top();
                       pq.pop();
                       int z=p.first;
                       int x=p.second;

                       if(x==d)
                        return dist[x];

                       for(int i=0;i<v[x].size();i++){
                            int y=v[x][i].dest;
                            int wt=v[x][i].weight;
                                if(dist[y]>dist[x]+wt){
                                    dist[y]=dist[x]+wt;
                                    pq.push({dist[y],y});
                                }
                       }
                  }
         }
};

int main(){
    Graph g(6);

      g.addEdge(0,1,4);
    g.addEdge(0,2,8);

     g.addEdge(2,4,3);
      g.addEdge(1,5,20);
      g.addEdge(2,3,9);
         g.addEdge(3,5,2);
      g.addEdge(4,3,1);
      g.addEdge(4,5,5);

      cout << g.dijkstra(0,5) << endl;


}
