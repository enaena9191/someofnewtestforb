int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    if (k == 0 || k == 1) return 0;
    int ans = 0, p = 1, l = 0;
    for (int r = 0; r < numsSize; r++) {
        p *= nums[r];
        while (p >= k) {
            p /= nums[l++];
        }
        ans += r - l + 1;
    }
    return ans;
}