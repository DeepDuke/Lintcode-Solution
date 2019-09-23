/*
拓扑排序判断有向图是否有环
*/
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        vector<vector<int> > graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        int cnt = 0;
        // build graph
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
            inDegree[prerequisites[i].first]++;
        }
        // topological sort 
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            cnt++;
            for(int i = 0; i < graph[now].size(); i++){
                int next = graph[now][i];
                inDegree[next]--;
                if(inDegree[next] == 0)  q.push(next);
            }
        }
        
        cout << "cnt: " << cnt << endl;
        return cnt == numCourses;
    }
};