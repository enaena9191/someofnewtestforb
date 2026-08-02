#include <string.h>

// 欧拉筛 O(n)
int countPrimes(int n) {
    if (n < 2) return 0;
    int is_prime[n];
    memset(is_prime, 0, sizeof(is_prime));
    int prime[n];
    int size = 0;
    for (int i = 2; i < n; i++) {
        if (!is_prime[i]) {
            prime[size++] = i;
        }
        for (int j = 0; j < size && i * prime[j] < n; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return size;
}

// 埃氏筛 O(nloglogn)

int MX = 5000001;
int INI[5000001] = {0};
// int PRI[5000001] = {0};
static int init = 0;
// static int cnt = 0;

void pri_init() {
    if (init) return;
    init = 1;
    INI[0] = 1, INI[1] = 1;
    for (int i = 2; i < MX; i++) {
        if (!INI[i]) {
            // PRI[cnt++] = i;
            double s = (double) MX / i;
            for (int j = i; j < s; j++) {
                INI[j * i] = 1;
            }
        }
    }
}

int countPrimes(int n) {
    pri_init();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += !INI[i];
    }
    return ans;
}