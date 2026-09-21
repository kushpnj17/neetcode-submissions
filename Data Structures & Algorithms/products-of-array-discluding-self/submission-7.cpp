class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 1);
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        vector<int> res(n, 1);
        int postfix = 1;
        for(int i = n - 1; i >= 0; i--){
            res[i] = prefix[i] * postfix;
            postfix *= nums[i];
        }

        // vector<int> res(n, 0);
        // for(int i = 0; i < n; i++){
        //     res[i] = prefix[i] * postfix[i];
        // }

        return res;
    }
};

// prefix: [1, 1, 2, 8]
// postfix: [48, 24, 6, 1]