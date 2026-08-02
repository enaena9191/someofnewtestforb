#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n), stk;
        int s = 0;

        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!stk.empty() && t > temperatures[stk[s - 1]]) {                
                ans[stk[s - 1]] = i - stk[s - 1];
                stk.pop_back();
                s--;
            }
            stk.push_back(i);
            s++;
        }

        return ans;
    }
};

/*
1 5 4 3 2 3 4 5 6
1 7 5 3 1 1 1 1 1
0 1 2 3 4 5

5 4 3 3

1 5 4 3 2 1 2 3 4
1 0 0 0 3 1 1 0
*/