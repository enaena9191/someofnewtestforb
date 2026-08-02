int hIndex(int* citations, int citationsSize) {
    int l=0,r=citationsSize-1;
    int m;
    while (l<=r) {
        m=(l+r)/2;
        if (citations[m]>=citationsSize-m) {
            r=m-1;
        } else {
            l=m+1;
        }
    }
    return citationsSize-m+1;
}