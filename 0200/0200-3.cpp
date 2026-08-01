#include <vector>

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
                
            }
        }
    }
};