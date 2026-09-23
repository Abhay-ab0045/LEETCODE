class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int target = totalSum - x;

        if (target < 0) return -1;
        int n = nums.size();
        int left = 0;
        int windowSum = 0;
        int maxLen = -1; 
        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            
            while (windowSum > target && left <= right) {
                windowSum -= nums[left];
                left++;
            }

            if (windowSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};