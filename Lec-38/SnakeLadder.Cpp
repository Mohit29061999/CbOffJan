///problem link: https://leetcode.com/problems/snakes-and-ladders/

class node{
    public:
    int x;
    
    int z; ///no of moves to go there
    
    node(int a,int c){
        x=a;
     
        z=c;
    }
};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        
        int move[n*n+1];
        int c=1;
        for(int i=n-1;i>=0;i--){
            int x=n-1-i;
         // cout << c << endl;
            if(x%2==0){
                for(int j=0;j<n;j++){
                    
                    move[c]=board[i][j];
                      c++;
                }
            }
            else{
                  for(int j=n-1;j>=0;j--){
                    move[c]=board[i][j];
                        c++;
                }
            }
          
        }
        
       for(int i=1;i<n*n+1;i++)
            cout << move[i] << " "; 
        
        queue<node>q;
        
        
           c=0;
        int x=1;
        node n1(x,0);
        q.push(n1);
        bool visited[n*n+1];
        for(int i=1;i<n*n+1;i++)
            visited[i]=false;
        visited[1]=true;
        while(!q.empty()){
            node n1=q.front();
            q.pop();
            int x=n1.x;
            int z=n1.z;
            
            if(x==(n*n))
                return z;
            
            for(int i=1;i<=6;i++){
                int y=x+i;
                if(y>(n*n))
                    continue;
                if(move[y]!=-1)
                    y=move[y];
                if(visited[y]==false){
                   node n2(y,z+1);
                    visited[y]=true;
                   // cout << y << " " << z+1 << endl;
                    q.push(n2);
                }
            }
        }
        
        return -1;
     
        
    }
};