class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int first = alg(nums, n-1, 1);
        int last = alg(nums, n-2, 0);
        return max(first, last);
    }

    int alg(vector<int>& nums, int start, int end){
        int n = nums.size();
        vector<int> dp(n+2, 0);

        for(int i = start; i >= end; i--){
            dp[i] = max(dp[i+1], dp[i+2] + nums[i]);
        }

        return dp[end];
    }
};

//  [3,4,3]
// including last elem
// n: 3
// start: 2
// end: 1
// dp: [0,0,0,0]