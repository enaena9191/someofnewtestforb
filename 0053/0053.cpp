#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, cur = 0;
        int n = nums.size();
        for (int x : nums) {
            cur = x + max(0, cur);
            ans = max(ans, cur);
        }
        return ans;
    }
};