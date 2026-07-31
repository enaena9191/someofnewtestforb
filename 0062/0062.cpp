#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int i = 1; i < min(m, n); i++) {
            ans = ans * (m + n - 1 - i) / i;
        }
        return ans;
        vector<int> f(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};

/*
1 1 1 1  1  1  1
1 2 3 4  5  6  7
1 3 6 10 15 21 28
1 4
1

C41 C72
C42
C63
C82 
8 7 2 1
*/