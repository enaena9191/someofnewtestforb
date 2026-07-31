#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1);
        dp[0] = INT_MAX, dp[1] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i + 1] = dp[i] + triangle[i][i];
            for (int j = i; j > 0; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j - 1];
            }
        }
        return ranges::min(dp);
    }
};

/*
0 max 2
1 max 3 4
2 max 6 5 7
3 max 4 1 8 3

*/