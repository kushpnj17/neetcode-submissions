class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < position.size(); i++){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());

        int fleets = 0;
        double highest = INT_MIN;
        for(int i = arr.size()-1; i >= 0; i--){
            double hrs = (target - arr[i].first) / static_cast<double>(arr[i].second);
            cout << hrs << endl;
            if(hrs > highest){
                fleets++;
                highest = hrs;
            }
        }

        return fleets;
    }
};
