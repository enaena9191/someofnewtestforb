class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') continue;
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '2';
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != '1') continue;
                        grid[nx][ny] = '2';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};