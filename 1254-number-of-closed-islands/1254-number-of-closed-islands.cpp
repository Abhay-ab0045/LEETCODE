class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<int>>& grid) {

        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {

                    
                    if (abs(delrow) + abs(delcol) != 1)
                        continue;

                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 0 &&
                        !vis[nrow][ncol]) {

                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (row == 0 || row == n - 1 ||
                    col == 0 || col == m - 1) {

                    if (grid[row][col] == 0 && !vis[row][col]) {
                        bfs(row, col, vis, grid);
                    }
                }
            }
        }

        
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid[row][col] == 0 && !vis[row][col]) {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};