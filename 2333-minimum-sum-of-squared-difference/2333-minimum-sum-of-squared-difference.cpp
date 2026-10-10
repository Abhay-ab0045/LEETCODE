class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        const int MAXV = 100000;
        vector<long long> cnt(MAXV + 2, 0);

        for (int i = 0; i < n; i++) {
            cnt[abs(nums1[i] - nums2[i])]++;
        }

        long long k = (long long)k1 + k2;

        for (int v = MAXV; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;

            if (k >= cnt[v]) {
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {
                cnt[v - 1] += k;
                cnt[v] -= k;
                k = 0;
            }
        }

        long long result = 0;
        for (long long v = 1; v <= MAXV; v++) {
            result += cnt[v] * v * v;
        }

        return result;
    }
};