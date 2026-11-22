class Solution {
public:
    int tribonacci(int n) {
        if(n < 1) {
            return 0;
        } else if (n < 3) {
            return 1;
        }

        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        int next = 2;

        for(int i = 3; i <= n; i++){
            next = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = next;
        }

        return next;
    }
};

// 4
// 0, 1, 1, 2, 4
// next: 4
// prev3: 1
// prev2: 2
// prev1: 4