class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        if(!list.count(endWord)) return 0;

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);

        int res = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string p = q.front(); q.pop();
                if(p == endWord) return res;

                for(const auto& s : list){
                    int count = 0;
                    for(int j = 0; j < s.size(); j++){
                        if(s[j] != p[j]){
                            count++;
                        }
                    }

                    if(count == 1 && !visited.count(s)) {
                        // cout << "neighbors of p: " << p << endl;
                        // cout << "s: " << s << endl;
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
            // cout << endl;
            res++;
        }

        return 0;
    }
};
