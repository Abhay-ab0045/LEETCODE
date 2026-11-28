class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        int maxFactor = 0;

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
            maxFactor = max(maxFactor, item[0]);
        }

        vector<pair<int, long long>> special;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            long long freeCount = 0;

            for (int j = factor; j <= maxFactor; j += factor) {
                freeCount += freq[j];
            }

            freeCount--;

            if (price < 2LL * minPrice && freeCount > 0) {
                special.push_back({price, freeCount});
            }
        }

        sort(special.begin(), special.end());

        long long remaining = budget;
        long long bonusPurchases = 0;

        for (auto& [price, count] : special) {
            long long canBuy = min(count, remaining / price);

            bonusPurchases += canBuy;
            remaining -= canBuy * price;
        }

        long long ans = 2 * bonusPurchases + remaining / minPrice;

        return (int)ans;
    }
};