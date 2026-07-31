#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), k = 0;
        for (int& x : grid[0]) { x += k; k = x; }
        k = 0;
        for (auto& g : grid) { g[0] += k; k = g[0]; }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};