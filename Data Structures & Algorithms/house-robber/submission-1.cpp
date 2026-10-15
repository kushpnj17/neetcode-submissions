class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }

    int dfs(int i, vector<int>& nums, vector<int> &dp){
        if(i >= nums.size()) return 0;
        
        if(dp[i] != -1) return dp[i];

        int result = max(nums[i] + dfs(i+2, nums, dp), dfs(i+1, nums, dp));
        dp[i] = result;

        return dp[i];
    }
};
