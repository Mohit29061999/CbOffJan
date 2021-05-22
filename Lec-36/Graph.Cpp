#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Graph{
    private:
    vector<vector<int>>v;  ///adjacency list
    int n;  ///number of vertex in graph


    public:
        Graph(int v1){
            n=v1;
            ///my graph is empty now
            for(int i=0;i<n;i++){
                vector<int>temp;
                v.push_back(temp);
            }
        }

        void addEdge(int x,int y,bool bidir=true){
            ///connect edge between x and y
            v[x].push_back(y);
            if(bidir){
                v[y].push_back(x);
            }
        }


        void bfs(bool visited[],int s=0){
            ///s tells us which index to start our bfs from

            queue<int>q;
            q.push(s);
                visited[s]=true;

            while(!q.empty()){
                cout << q.front() << " ";
                int x=q.front();
                q.pop();
                for(int i=0;i<v[x].size();i++){
                        int y=v[x][i];
                    if(visited[y]==false){
                        q.push(y);
                            visited[y]=true;
                    }
                }
            }

        }


        ///used when graph is disconnected
        ///time complexity is O(v+e) where v is no of vertex and e is no of edge
        void bfsAll(){
            bool visited[n];
            for(int i=0;i<n;i++)
                visited[i]=false;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ///call bfs from here
                    bfs(visited,i);
                }
            }
        }

        void dfs(int s,bool visited[]){
            ///make s visited
            visited[s]=true;
            cout << s << " ";

            ///try adjacent edges of s one by one(depth first)
            for(int i=0;i<v[s].size();i++){
                    int y=v[s][i];
                if(visited[y]==false){
                        ///call dfs for y
                    dfs(y,visited);
                }
            }
        }

        ///when graph is disconnected
        ///time complexity is O(v+e) where v is no of vertex and e is no of edge
        void dfsAll(){
            bool visited[n];
            for(int i=0;i<n;i++)
                visited[i]=false;

            for(int i=0;i<n;i++){
                if(visited[i]==false)
                    dfs(i,visited);
            }
        }
};

int main(){
    Graph g(6);

      g.addEdge(0,1);
    g.addEdge(0,2);
     g.addEdge(0,3);
      g.addEdge(2,5);
      g.addEdge(1,4);

      g.dfsAll();


}
