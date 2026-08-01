#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') continue; // visited or water
                ans++;
                grid[i][j] = '2'; //visited
                std::queue<std::pair<int, int>> qd;
                qd.push({i, j});
                while (!qd.empty()) {
                    auto [x, y] = qd.front();
                    qd.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != '1') continue;
                        grid[nx][ny] = '2';
                        qd.push({nx, ny});
                    }
                }
            }
        }
        return ans;
    }
};