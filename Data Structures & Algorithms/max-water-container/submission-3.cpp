class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l = 0;
        int r = heights.size() - 1;
        
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r-l);
            max_area = max(max_area, area);
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }

        return max_area;
    }
};
