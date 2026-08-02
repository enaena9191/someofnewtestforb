#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            int t = temperatures[i];
            while (!stk.empty() && t >= temperatures[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }

        return ans;
    }
};

/*
1 5 4 3 2 3 4 5 6
1 7 5 3 1 1 1 1 1
0 1 2 3 4 5
*/