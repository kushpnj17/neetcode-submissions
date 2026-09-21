class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for (string s : strs){
            vector<int> code(26, 0);
            for(char c : s){
                code[c - 'a']++;
            }

            string key;
            for(int n : code){
                key += n +',';
            }

            umap[key].push_back(s);
        }

        vector<vector<string>> answer;
        for(auto p : umap){
            answer.push_back(p.second);
        }

        return answer;
    }
};
