class Solution {
public:
    int numSplits(string s) {
        if(s.size() < 2)
            return 0;
        vector<int> leftCharCount(s.size(), 0), rightCharCount(s.size(), 0);
        unordered_set<char> firstSeen;
        int charCount = 0;
        for(int i = 0; i < s.size(); i++) {
            if(firstSeen.find(s[i]) == firstSeen.end()) {
                charCount++;
                firstSeen.insert(s[i]);            
            }
            leftCharCount[i] = charCount;
        }
        firstSeen.clear();
        charCount = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(firstSeen.find(s[i]) == firstSeen.end()) {
                charCount++;
                firstSeen.insert(s[i]);            
            }
            rightCharCount[i] = charCount;
        }
        int goodStringCount = 0;
        for(int i = 1; i < s.size(); i++) {
            if(leftCharCount[i-1] == rightCharCount[i])
                goodStringCount++;
        }
        return goodStringCount;
    }
};
