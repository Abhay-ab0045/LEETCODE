class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({digitSum(nums[i]), nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = get<2>(v[i]);
            target[originalIndex] = i;
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[i] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;
                j = target[j];
            }

            ans += cycleSize - 1;
        }

        return ans;
    }
};