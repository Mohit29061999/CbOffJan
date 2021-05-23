#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool dfs(bool visited[],bool rec[],int i,vector<int> adj[]){
    visited[i]=true; ///ith node is visited
    rec[i]=true;  ///ith node recursion me h
    
    for(int j=0;j<adj[i].size();j++){
        int y=adj[i][j];
        if(visited[y]==false){
            bool c=dfs(visited,rec,y,adj);
            if(c==true)
            return true;
        }
        else if(rec[y]==true && visited[y]==true)
        return true;
    }
    
    rec[i]=false;
    return false;
    
}

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{  
	    bool visited[V],rec[V]; ///visited[i]: whether a vertex is visited or not
	                            ///rec[i]: whether recursion is working or not
	       int n=V;                     
	   for(int i=0;i<n;i++){
	       visited[i]=false;
	       rec[i]=false;
	   }
	   
	   for(int i=0;i<n;i++){
	       if(visited[i]==false){
	           bool c=dfs(visited,rec,i,adj);
	           if(c==true)
	           return true;
	       }
	   }
	   
	   return false;
	   
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends