class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int l = dp(nums, n-2, 0);
        int r = dp(nums, n-1, 1);

        return max(l, r);
    }

    int dp(vector<int>& nums, int start, int end){
        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i >= end; i--){
            int next = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = next;
        }

        return prev1;
    }
};
