class Solution {
//     Memory can also be optimized. one set that stores first position of any character S and another that stores the last E. Let s = 0; and e = num of different char in string. for(i = 0 to end - 1) if(s[i] in A) s++; if(s[i] in B) e--; Now if(s == e) add 1 
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
