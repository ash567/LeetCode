// Took 22 minutes
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() == 0)
            return 0;
        int st, en, ans;
        st = en = ans = 0;
        unordered_map<int, int> numCount;
        while(st < tree.size() && en < tree.size()) {
            if(numCount.find(tree[en]) != numCount.end() || numCount.size() < 2) {
                numCount[tree[en]]++;
                en++;
                ans = max(en - st, ans);
            } else {
                numCount[tree[st]]--;
                if(numCount[tree[st]] == 0)
                    numCount.erase(tree[st]);
                st++;
            }
        }
        return ans;
    }
};
