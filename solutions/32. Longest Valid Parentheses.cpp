class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> openPos;
        // vector<int> maxAtEnd(s.size() + 1, 0);
        int maxSize = 0;
        openPos.push(-1);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                openPos.push(i);
            } else {
                openPos.pop();
                if(openPos.empty())
                    openPos.push(i);
                else
                    maxSize = max(maxSize, i - openPos.top());
            }
        }
        return maxSize;
    }
};
