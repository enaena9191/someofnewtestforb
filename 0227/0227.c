#include <string.h>
#include <ctype.h>

int calculate(char* s) {
    int n = strlen(s);
    int stk[n], top = 0, num = 0;
    char preSign = '+';
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (int)(s[i] - '0');
        }
        if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
            switch (preSign) {
                case '+':
                    stk[top++] = num; break;
                case '-':
                    stk[top++] = -num; break;
                case '*':
                    stk[top - 1] *= num; break;
                case '/':
                    stk[top - 1] /= num;
            }
            preSign = s[i];
            num = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < top; i++) ans += stk[i];
    return ans;
}

/*
1+2*3*4
[1,6]
*/