class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;

        int maxi = 0;
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                mp[nums[i + 1]]++;

                if (mp[nums[i + 1]] > maxi) {
                    maxi = mp[nums[i + 1]];
                    ans = nums[i + 1];
                }
            }
        }

        return ans;
    }
};