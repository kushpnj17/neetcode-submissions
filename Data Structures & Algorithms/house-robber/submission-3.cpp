class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);

        dp[n-1] = nums[n-1];
        dp[n-2] = max(dp[n-1], nums[n-2]);
        for(int i = n - 3; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
        }
        
        return dp[0];
    }

    // int dfs(int i, vector<int>& nums, vector<int> &dp){
    //     if(i >= nums.size()) return 0;
        
    //     if(dp[i] != -1) return dp[i];

    //     int result = max(nums[i] + dfs(i+2, nums, dp), dfs(i+1, nums, dp));
    //     dp[i] = result;

    //     return dp[i];
    // }
};
