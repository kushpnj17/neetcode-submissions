class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;

        int k = INT_MAX;
        while(l <= r){
            int mid = l + (r-l) / 2;
            int hrs = 0;
            for(int n : piles){
                hrs += n / mid;
                if(n % mid != 0){
                    hrs++;
                }
            }

            // cout << "mid: " << mid << endl;
            // cout << "hrs: " << hrs << endl;

            if (hrs <= h){
                k = min(mid, k);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return k;
    }
};
