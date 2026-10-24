class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        string alph = "abcdefghijklmnopqrstuvwxyz";
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

                for(int j = 0; j < p.size(); j++){
                    string s = p;
                    for(int k = 0; k < 26; k++){
                        s[j] = alph[k];
                        if(list.count(s) && !visited.count(s)){
                            q.push(s);
                            visited.insert(s);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};
