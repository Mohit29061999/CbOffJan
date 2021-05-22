#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <limits.h>
using namespace std;


///prim's algo
///time complexity is O((v+e)*logv)
///nature is greedy
void Mst(vector<vector<pair<int,int>>>&v){
    int n=v.size();
    ///maintain two set one for vertex visited and other for vertex non-visited
    bool visited[n];
    int key[n];
    int par[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        key[i]=INT_MAX;
        par[i]=-1;
    }

    set<pair<int,int>>s;  ///to store connection of vertex finalised for mst

    s.insert({0,0});

    par[0]=-1;
    key[0]=0;

    while(!s.empty()){
          pair<int,int>p = *(s.begin());
          int x=p.second;  ///current vertex
          s.erase({p.first,p.second});  ///remove it from set
            visited[x]=true;

          for(int i=0;i<v[x].size();i++){
                int y=v[x][i].first;
                int wt=v[x][i].second;
            if(visited[y]==false && key[y]>wt){
                    if(s.find({key[y],y})!=s.end()){
                        ///update it
                        s.erase({key[y],y});

                    }

                    ///insert this new entry in set
                    key[y]=wt;
                    par[y]=x;
                    s.insert({key[y],y});
            }
          }
    }

    ///print mst
    for(int i=1;i<n;i++){
        cout << par[i] << " " << i << " " << key[i] << endl;
    }


}


int main(){
    vector<vector<pair<int,int>>>v;  ///first value gives edge connected to and second value gives weight



    int n;
    cin>>n;
     for(int i=0;i<n;i++){
        vector<pair<int,int>>temp;
        v.push_back(temp);
     }
    int e;
    cin>>e;


    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;

        v[x].push_back({y,w});
         v[y].push_back({x,w});

    }

    Mst(v);
}


