#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1), nums;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i);
        }

        k--;
        string ans;

        for (int l = n; l >= 1; l--) {
            int idx = k / fact[l - 1];
            k %= fact[l - 1];

            ans += char('0' + nums[idx]);
            nums.erase(nums.begin() + idx);
        }

        return ans;
    }
};