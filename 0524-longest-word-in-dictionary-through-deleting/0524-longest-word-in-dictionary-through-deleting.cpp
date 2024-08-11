class Solution {
public:

    static bool cmp(string &s1, string &s2) {
        if(s1.size() != s2.size())
            return s1.size() > s2.size();
        return s1 < s2;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        for(int i=0;i<dictionary.size();i++) {
            string t = dictionary[i];
            if(match(s,t)) {
                return t;
            }

        }
        return "";
        
    }

    bool match(string s, string t) {
        int l = 0, r = 0;
        while(l < s.size() && r < t.size()) {
            if(s[l] == t[r]) {
                l ++;
                r ++;
            }
            else {
                l ++;
            }
        }
        if(r == t.size()) return true;
        return false;
    }
};