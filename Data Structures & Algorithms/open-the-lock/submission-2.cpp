class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        if(deadend.count("0000")) return -1;
        
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string t = q.front(); q.pop();
                if(t==target) return moves;

                for(int k = 0; k < 4; k++){
                    string s1 = t;
                    if(s1[k] == '0'){
                        s1[k] = '9';
                    } else {
                        s1[k]--;
                    }
                    if(!deadend.count(s1) && !visited.count(s1)){
                        q.push(s1);
                        visited.insert(s1);
                    }

                    string s2 = t;
                    if(s2[k] == '9'){
                        s2[k] = '0';
                    } else {
                        s2[k]++;
                    }
                    if(!deadend.count(s2) && !visited.count(s2)){
                        q.push(s2);
                        visited.insert(s2);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};