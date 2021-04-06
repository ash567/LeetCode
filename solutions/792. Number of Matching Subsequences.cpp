class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector< set<int> > charPos('z' - 'a' + 1, set<int>());
        for(int i = 0; i < s.size(); i++) {
            charPos[s[i] - 'a'].insert(i);
        }
        int wordCount = 0;
        for(int i = 0; i < words.size(); i++) {
            bool isSubSeq = true;
            int lastIndex = -1;
            for(int j = 0; j < words[i].size(); j++) {
                auto posIterator = charPos[words[i][j] - 'a'].upper_bound(lastIndex);
                if(posIterator == charPos[words[i][j] - 'a'].end()) {
                    isSubSeq = false;
                    break;
                }
                lastIndex = *(posIterator);
            }
            if(isSubSeq)
                wordCount++;
        }
        return wordCount;
    }
};
