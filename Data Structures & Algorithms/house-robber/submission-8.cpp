class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        int next = max(prev1, prev2);

        for(int i = 1; i < nums.size(); i++){
            next = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = next;
        }

        return next;
    }
};
