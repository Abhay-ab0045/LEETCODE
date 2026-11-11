class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);
        long long extra1 = need1 - common;
        long long extra2 = need2 - common;

        long long ans = common * min((long long)costBoth,
                                    (long long)cost1 + cost2);

        ans += extra1 * min(cost1, costBoth);
        ans += extra2 * min(cost2, costBoth);

        return ans;
    }
};