int trailingZeroes(int n) {
    int i = n, cnt2 = 0, cnt5 = 0;
    while (i > 0) {
        i /= 2;
        cnt2 += i;
    }
    i = n;
    while (i > 0) {
        i /= 5;
        cnt5 += i;
    }
    return cnt2 < cnt5 ? cnt2 : cnt5;
}

int trailingZeroes(int n) {
    int cnt = 0;
    while (n > 0) {
        n /= 5;
        cnt += n;
    }
    return cnt;
}

/*
n/2 2s
n/2^2 4s 2s

23
11 11
5 11+5
2 11+5+2
1 11+5+2+1

*/