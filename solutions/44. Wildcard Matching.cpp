class Solution {
    bool isMatchHelper(string&s, int n, string&p, int m, unordered_map<char, set<int> >& charPos, vector<vector<int>>& dpArray) {
        if(n == s.size() and m == p.size())
            return true;
        else if(n >= s.size() or m >= p.size())
            return false;
        else if (dpArray[n][m] != 0) {
            return (dpArray[n][m] == 1);
        }
        
        bool dpArrayValue = false;
        if(p[m] != '?' and p[m] != '*') {
            dpArrayValue =  ((s[n] == p[m]) and isMatchHelper(s, n + 1, p, m + 1, charPos, dpArray));
        } else if(p[m] == '?') {
            dpArrayValue = isMatchHelper(s, n + 1, p, m + 1, charPos, dpArray);
        } else {
            int newN = n, newM = m, gap = 0;
            while(p[newM] == '*' or p[newM] == '?') {
                if(p[newM] == '?')
                    gap++;
                newM++;
            }
            for(auto it = charPos[p[newM]].lower_bound(n + gap); it != charPos[p[newM]].end() and !dpArrayValue; it++) {
                if(isMatchHelper(s, *it + 1, p, newM + 1, charPos, dpArray))
                    dpArrayValue = true;
            }
        }
        return ((dpArray[n][m] = dpArrayValue ? 1 : -1) == 1);
    }
    
public:
    bool isMatch(string s, string p) {        
        s = s + '#';
        p = p + '#';
        vector<vector<int> > dpArray(s.size(), vector<int> (p.size(), 0));
        unordered_map<char, set<int> > charPos;
        set<char> charSet;
        for(int i = 0; i < s.size(); i++) {
            charPos[s[i]].insert(i);
        }
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == '?' or p[i] == '*')
                continue;
            charSet.insert(p[i]);
        }
        for(char c : charSet) {
            if(charPos.find(c) == charPos.end())
                return false;
        }
        // cout << s << endl << p << endl;
        return isMatchHelper(s, 0, p, 0, charPos, dpArray);
    }
};
