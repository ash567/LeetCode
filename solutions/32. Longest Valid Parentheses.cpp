class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> openPos;
        vector<int> maxAtEnd(s.size() + 1, 0);
        int maxSize = 0;
        if(s[0] == '(')
            openPos.push(0);
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '(') {
                openPos.push(i);
            } else if(!openPos.empty()) {
                int endSize = i - openPos.top() + 1;
                endSize += maxAtEnd[openPos.top()];
                openPos.pop();
                maxAtEnd[i + 1] = endSize;
                maxSize = max(maxSize, endSize);
            }
        }
        return maxSize;
    }
};
