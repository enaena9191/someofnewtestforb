#include <string>
#include <vector>
#include <array>
#include <cstdint>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int total = 0;
        for (auto& w : words) total += w.size();

        vector<array<int, 26>> child;
        vector<int8_t> end;
        child.reserve(total + 1);
        end.reserve(total + 1);
        child.push_back({});
        end.push_back(false);

        for (auto& w : words) {
            int cur = 0;
            for (char c : w) {
                c -= 'a';
                if (!child[cur][c]) {
                    child[cur][c] = child.size();
                    child.push_back({});
                    end.push_back(false);
                }
                cur = child[cur][c];
            }
            end[cur] = true;
        }

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<string> ret;
        int m = board.size(), n = board[0].size();

        auto dfs = [&] (this auto&& dfs, int i, int j, int cur, string& cw) -> bool {
            cw.push_back(board[i][j]);
            char tmp = board[i][j];
            board[i][j] = '#'; // visited.
            if (end[cur]) {
                ret.push_back(cw);
                end[cur] = false;
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#') continue;
                int c = board[x][y] - 'a';
                int nxt = child[cur][c];
                if (nxt && !dfs(x, y, nxt, cw)) child[cur][c] = 0; // dfs完后不再有用，断开。
            }

            board[i][j] = tmp; // revert
            cw.pop_back();

            bool alive = end[cur];
            if (!alive) {
                for (auto b : child[cur]) {
                    if (b) {
                        alive = true;
                        break;
                    }
                }
            }
            return alive;
        };

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string cw;
                if (child[0][board[i][j] - 'a']) dfs(i, j, child[0][board[i][j] - 'a'], cw);
            }
        }
        return ret;
    }
};