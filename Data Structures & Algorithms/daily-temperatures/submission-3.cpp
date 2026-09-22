class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int high = temperatures[0];
        stack<pair<int,int>> s;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            // high = max(high, temperatures[i]);

            while(!s.empty() && s.top().first < temperatures[i]){
                res[s.top().second] = i - s.top().second;
                s.pop();
            }

            s.push({temperatures[i], i});
        }

        return res;
    }
};
