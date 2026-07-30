#include <string>
#include <vector>
using namespace std;

int BIT = 0; // 0-4 up to 15

class Fenwick {
    int n;
    vector<int> f;
public:
    Fenwick(int n) : n(n), f(n + 1) {
        for (int i = 1; i <= n; i++) {
            f[i]++;
            int nxt = i + (i & -i);
            if (nxt <= n) f[nxt] += f[i];
        }
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i) f[i] += val;
    }

    // 返回第k小可用数字
    int kth(int k) {
        int pos = 0;
        for (int p = BIT; p >= 0; p--) {
            int nxt = pos + (1 << p);
            if (nxt <= n && f[nxt] < k) {
                pos = nxt;
                k -= f[nxt];
            }
        }

        return pos + 1;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        while ((1 << (BIT + 1)) <= n) BIT++;

        vector<long long> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;

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