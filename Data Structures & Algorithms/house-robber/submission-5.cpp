class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // vector<int> dp(n, 0);

        // dp[n-1] = nums[n-1];
        // dp[n-2] = max(dp[n-1], nums[n-2]);
        int prev2 = nums[n-1];
        int prev1 = max(prev2, nums[n-2]);
        for(int i = n - 3; i >= 0; i--){
            int next = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = next;
        }
        
        return prev1;
    }
};
