class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minH;

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                minH.push(diff);

                if (minH.size() > ladders) {
                    bricks -= minH.top();
                    minH.pop();
                }

                if (bricks < 0)
                    return i;
            }
        }

        return heights.size() - 1;
    }
};