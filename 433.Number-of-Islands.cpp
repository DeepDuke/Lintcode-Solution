class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    struct Node{
        int col, row;
    };
    int cols[4] = {0, 0, -1, 1};
    int rows[4] = {-1, 1, 0, 0};
    
    bool canVisit(vector<vector<bool> > &grid, vector<vector<bool> > &visited, Node node){
        // 越界
        if(node.row < 0 || node.row >= grid.size() || node.col < 0 || node.col >= grid[0].size()) return false;
        // 进入过队列
        if(visited[node.row][node.col]) return false;
        // 不是陆地
        if(grid[node.row][node.col] == 0) return false;
        return true;
    }
    void bfs(vector<vector<bool> > &grid, vector<vector<bool> > &visited, int row, int col){
        queue<Node> q;
        Node node;
        node.row = row; node.col = col;
        q.push(node);
        visited[row][col] = true; // 入队
        while(!q.empty()){
            Node nowNode = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                Node nextNode;
                nextNode.row = nowNode.row + rows[i]; nextNode.col = nowNode.col + cols[i];
                if(canVisit(grid, visited, nextNode)){
                    q.push(nextNode);
                    visited[nextNode.row][nextNode.col] = true;
                }
                
            }
        }
    }
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.size() == 0) return 0;
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                Node node;
                node.row = i; node.col = j;
                if(canVisit(grid, visited, node)){
                    cout <<"cnt: " << cnt << endl;
                    bfs(grid, visited, i, j);
                    cout << "after bfs\n";
                    cnt++;
                    
                }
            }
        }
        return cnt;
    }
};
