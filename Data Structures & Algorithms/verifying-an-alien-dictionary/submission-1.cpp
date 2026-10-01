class Solution {
    unordered_map<char, int> ord;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); i++){
            ord[order[i]] = i;
        }

        vector<string> sorted = words;
        return is_sorted(sorted.begin(), sorted.end(), [this](const string &a, const string &b){
            return comparator(a,b);
        });

    }

    bool comparator(const string &a, const string &b){
        int n = min(a.size(), b.size());

        for(int i = 0; i < n; i++){
            if(ord[a[i]] < ord[b[i]]){
                return true;
            }

            if(ord[a[i]] > ord[b[i]]){
                return false;
            }
        }

        return a.size() < b.size();
    }
};