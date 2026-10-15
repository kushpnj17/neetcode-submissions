class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev1 = 1;
        int next = 1;

        for(int i = 2; i <= n; i++){
            next = prev2 + prev1;
            prev2 = prev1;
            prev1 = next;
        }

        return next;
    }
};
