#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        auto& og = obstacleGrid;
        int m = og.size(), n = og[0].size();
        if (og[0][0] == 1 || og[m - 1][n - 1]) return 0;
        vector<int> f(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) f[i] = min(f[i - 1], og[0][i] ^ 1);
        for (int i = 1; i < m; i++) {
            if (og[i][0]) f[0] = 0;
            for (int j = 1; j < n; j++) {
                f[j] = og[i][j] ? 0 : (f[j] + f[j - 1]);
            }
        }
        return f[n - 1];
    }
};