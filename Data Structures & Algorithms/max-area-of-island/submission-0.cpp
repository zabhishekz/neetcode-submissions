class Solution {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxArea = 0;
public:
    int bfs(vector<vector<int>>& grid, int r, int c){
        grid[r][c] = 0;
        queue<pair<int,int>> q;
        q.push({r,c});
        int area = 0;
        while(!q.empty()){
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            area++;
            for(int i = 0; i < 4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr >= 0 and nr < grid.size() and nc >= 0 and nc < grid[0].size() and grid[nr][nc] == 1){
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                }
            }
        }        
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    int currArea = bfs(grid, i, j);
                    maxArea = max(maxArea, currArea);  
                }
            }
        }

        return maxArea;
    }
};
