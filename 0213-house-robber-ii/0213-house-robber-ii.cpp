class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        int prev = 0;
        int prev2 = 0;

        for (int i = start; i <= end; i++) {
            int rob = nums[i] + prev2;
            int skip = prev;

            int curr = max(rob, skip);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int case1 = solve(nums, 0, n - 2);
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};