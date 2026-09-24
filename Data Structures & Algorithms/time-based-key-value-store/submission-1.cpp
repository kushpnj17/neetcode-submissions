class TimeMap {
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    // [1,2,3,5,6,7]   timestamp is 4
    string get(string key, int timestamp) {
        auto it = upper_bound(umap[key].begin(), umap[key].end(), timestamp, [](int timestamp, const pair<int, string>& p) { return timestamp < p.first; });

        if(it != umap[key].begin()){
            --it;
            return it->second;
        }

        return "";
    }
};
