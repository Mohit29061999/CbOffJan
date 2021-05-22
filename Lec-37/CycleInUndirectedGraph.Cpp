///problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


 // } Driver Code Ends

class Solution{
    bool dfs(int i,vector<int>adj[],bool visited[],int par){
    visited[i]=true;  ///ith node is now visited

    ///try adjacent node of i
    for(int j=0;j<adj[i].size();j++){
        int y=adj[i][j];
        if(visited[y]==false){
            ///visit y
            bool c=dfs(y,adj,visited,i);
            if(c==true)
            return true;
        }

        ///if it is already visited
        else if(par!=y){
            return true;
        }
    }

    return false;
}
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	   bool visited[V];
	   for(int i=0;i<V;i++)
	   visited[i]=false;

	   for(int i=0;i<V;i++){
	       if(visited[i]==false){
                   bool c = dfs(i,adj,visited,-1);
                    if(c==true)
                    return true;
	       }
	   }
	   return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
