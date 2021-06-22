class Solution {
//     assuming indices are in sorted order
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int, int> indMapping;
        for(int i = 0; i < indices.size(); i++) {
            indMapping[indices[i]] = i;
        }
        sort(indices.begin(), indices.end());
        string ans;
        int i = 0, j = 0;
        while(i < s.size() and j < indices.size()) {
            if(i == indices[j]) {
                if(s.substr(i, sources[indMapping[indices[j]]].size()) == sources[indMapping[indices[j]]]) {
                    ans += targets[indMapping[indices[j]]];
                    i += sources[indMapping[indices[j]]].size();
                }
                j++;
            } else {
                ans += s.substr(i, indices[j] - i);
                i = indices[j];
            }
        }
        ans += s.substr(i, s.size() - i);
        return ans;
    }
};
