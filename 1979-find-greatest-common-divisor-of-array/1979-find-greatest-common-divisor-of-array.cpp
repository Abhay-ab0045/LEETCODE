class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());
        
        return gcd(min_num, max_num);
    }
};