class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> sq(n);

        for(int i = 0; i<n;i++){
            sq[i] = (long long) nums[i] * nums[i];
        }
        sort(sq.begin(),sq.end());


        int minusCount = n/2;
        long long result = 0;

        for( int i=0;i<minusCount; i++){
            result -=sq[i];
        }

        for(int i= minusCount ; i<n;i++){
            result += sq[i];
        }
        return result;
    }
};