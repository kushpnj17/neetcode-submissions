class Solution {
public:

    string encode(vector<string>& strs) {
        string r;
        for(string s : strs){
            r += to_string(s.size()) + "," + s;
        }

        cout << r;
        return r;
    }

    vector<string> decode(string s) {
        vector<string> r;

        int i = 0;
        while(i < s.size()) {
            int comma = s.find(',', i);
            int n = stoi(s.substr(i, comma - i));
            i = comma + 1;
            string str = s.substr(i, n);
            r.push_back(str);
            i += n;
        }

        return r;
    }
};

// "5,hello5,world"
// comma: 8
// i: 14
// length: 8-7=1
// n: 5
// str: world






