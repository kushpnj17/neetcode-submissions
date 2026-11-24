class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;
        int next = min(prev2, prev1);

        for(int i = 2; i <= cost.size(); i++){
            next = min(cost[i-1] + prev1, cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = next;
        }

        return next;
    }
};
