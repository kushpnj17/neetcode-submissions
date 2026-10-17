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
        int prev1 = 0;
        int prev2 = 0;

        for(int i = start; i >= end; i--){
            int next = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = next;
        }

        return prev1;
    }
};

//  [3,4,3]
// including last elem
// n: 3
// start: 2
// end: 1
// dp: [0,0,0,0]