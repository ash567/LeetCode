class Solution {    
    
public:
        void countF(const vector<int>& flower, const vector<int>& persons, vector<int>& ans) {
        int j = 0;
        for(int i = 0; i < persons.size(); i++) {
            while(j < flower.size() and flower[j] <= persons[i]) {
                j++;
            }
            ans[i] += j;
        }
        return;
    }
    
    void countFF(const vector<int>& flower, const vector<int>& persons, vector<int>& ans) {
        int j = 0;
        for(int i = 0; i < persons.size(); i++) {
            while(j < flower.size() and flower[j] < persons[i]) {
                j++;
            }
            ans[i] -= j;
        }
        return;
    }
​
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> startF(flowers.size(), 0), endF(flowers.size(), 0), ans(persons.size(), 0), answer(persons.size(), 0);
        vector<pair<int, int> > index(persons.size());
        
        for(int i = 0; i < persons.size(); i++) {
            index[i] = {persons[i], i};
        }
        sort(persons.begin(), persons.end());
        sort(index.begin(), index.end());
        
        for(int i = 0; i < flowers.size(); i++) {
            startF[i] = flowers[i][0];
            endF[i] = flowers[i][1];
        }
        sort(startF.begin(), startF.end());
        sort(endF.begin(), endF.end());
        
        countF(startF, persons, ans);
        countFF(endF, persons, ans);
        
        for(int i = 0; i < ans.size(); i++) {
            answer[index[i].second] = ans[i];
        }
