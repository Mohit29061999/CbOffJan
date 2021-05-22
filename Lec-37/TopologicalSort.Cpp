///problem link: https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        vector<vector<int>>v; ///to store pre-req graph

        for(int i=0;i<numCourses;i++){
               vector<int>temp;
            v.push_back(temp);
        }

        for(int i=0;i<m;i++){
            int x=prerequisites[i][0];  ///to do x we have to do y
            int y=prerequisites[i][1];
            v[y].push_back(x);
        }

        int indeg[numCourses];
        for(int i=0;i<numCourses;i++)
            indeg[i]=0;

         for(int i=0;i<m;i++){
            int x=prerequisites[i][0];
             indeg[x]++;

        }

        int c=0;

        ///start with 0 indegree courses
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
                c++;
            }
        }

        cout << c << endl;


        while(!q.empty()){
            ///take out the first course and do it
            int x=q.front();
            q.pop();

            ///remove the dependency due to x as we have done it
            for(int i=0;i<v[x].size();i++){
                       indeg[v[x][i]]--;
                ///if this course is not dependent on anyone now
                ///then do it
                 if(indeg[v[x][i]]==0){
                     q.push(v[x][i]);
                     c++;
                 }

            }
        }

        if(c==numCourses){
            return true;
        }
        return false;

    }
};
