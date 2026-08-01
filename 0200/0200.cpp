class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //auto dfs = [&](this auto&& dfs, int i, int j) -> void {
        auto dfs = [&] (this auto&& dfs, int i, int j) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (grid[i][j] != '1') return;
            grid[i][j] = '2';
            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};