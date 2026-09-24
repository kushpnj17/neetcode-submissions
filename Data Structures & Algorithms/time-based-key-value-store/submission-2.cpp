class TimeMap {
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    // [1]
    string get(string key, int timestamp) {
        vector<pair<int, string>> &times = umap[key];
        int l = 0;
        int r = times.size()-1;
        string res = "";

        while(l <= r){
            int mid = l + (r-l) / 2;

            if(times[mid].first == timestamp){
                return times[mid].second;
            } else if (times[mid].first < timestamp) {
                res = times[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
