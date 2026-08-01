#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 0 for not rob, 1 for rob
        int f[2][2] = {};
        f[0][0] = 0, f[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            int j = i + 1 & 1;
            f[i & 1][0] = max(f[j][0], f[j][1]);
            f[i & 1][1] = nums[i] + f[j][0];
        }
        return max(f[n - 1 & 1][0], f[n - 1 & 1][1]);
    }
};

/*
12345
  1 5 2 2 5
f 0 1 2 3 4 5
0 0 1 5 5 7
1 1 5 3 7 10
*/