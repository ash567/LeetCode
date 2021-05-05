class Solution {
    string repStr(string s, int n) {
        string ans = "";
        while(n--) {
            ans += s;
        }
        return ans;
    }
public:
    string decodeString(string s) {
        stack< pair<int, string> > pile;
        string repS = "";
        int rep = 1;
        //pile.push({rep, repS});
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '[') {
                i++;
            } else if(s[i] == ']') {
                auto pileHead = pile.top();
                pile.pop();
                repS = pileHead.second + repStr(repS, rep);
                rep = pileHead.first;
                i++;
            } else if(isalpha(s[i])) {
                repS += s[i];
                i++;
            } else {
                pile.push({rep, repS});
                int j = i;
                while(j < s.size() && isdigit(s[j]))
                    j++;
                rep = stoi(s.substr(i, j - i));
                repS = "";
                i = j;
            }
        }
        return repS;
    }
};
