//problem link: https://leetcode.com/problems/rotting-oranges/


class Fruit{
    public:
    int x;
    int y;
    int d;

    Fruit(int a,int b,int c){
        x=a;
        y=b;
        d=c;
    }

};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<Fruit>q;
        ///insert already rotten orange in queue first
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    Fruit f(i,j,0);
                    q.push(f);
                }
            }
        }

        int ans =0; ///to store max day at which an orange becomes rotten


        ///one by take one orange from queue and make its adjacent orange rotten
        while(!q.empty()){
            Fruit f=q.front();
            q.pop();

            int x=f.x;
            int y=f.y;
            int d=f.d;
            ans =d;

            ///make its adjacent fresh orange rotten
            ///check for rotten orange in down direction
            if(x+1<n && grid[x+1][y]==1){
                grid[x+1][y]=2;
                Fruit f1(x+1,y,d+1);
                q.push(f1);

            }

            ///check for rotten orange in up direction
              if(x-1>=0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                Fruit f1(x-1,y,d+1);
                q.push(f1);

            }

            ///check for rotten orange in right direction

             if(y+1<m && grid[x][y+1]==1){
                grid[x][y+1]=2;
                Fruit f1(x,y+1,d+1);
                q.push(f1);

            }

            ///check for rotten orange in left direction
              if(y-1>=0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                Fruit f1(x,y-1,d+1);
                q.push(f1);

            }


        }

        ///check if all orange are rotten or not
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;


    }
};
