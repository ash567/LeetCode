long MOD = (1e9 + 7);
​
// Wasted a long time in making it log n
class Solution {
public:
    int countVowelPermutation(int n) {
        unordered_map<char, long> startCount, next;
        startCount = next = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
        list<char> vovels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, list<char> > follow;
        cout << next['a'] << endl;
        follow = {{'a', {'e'}}, {'e', {'a', 'i'}}, {'i', {'a', 'e', 'o', 'u'}}, {'o', {'i', 'u'}}, {'u', {'a'}}};
        for(int i = 2; i <= n; i++) {
            for(char v : vovels) {
                next[v] = 0;
                for(char f : follow[v]) {
                    next[v] += startCount[f];
                    next[v] %= MOD;
                }
            }
            for(char v : vovels) {
                startCount[v] = next[v];
            }
        }
        long permCount = 0;
        for(char v : vovels) {
            permCount += next[v];
            permCount %= MOD;
        }
        return permCount;
        // int m = 1;
        // while((1 << m) <= n) {
        //     for(char v : vovels) {
        //         startCount[v][m] = 0;
        //         for(char f: follow[v]) {
