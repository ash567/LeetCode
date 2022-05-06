class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        for(string &s : words)
            wordCount[s]++;
        priority_queue<pair<int, string>, vector<pair<int, string> >, greater<pair<int, string> > > pq;
        int pqSize = 0;
        for(auto p : wordCount) {
            pair<int, string> invPair = make_pair((p.second), p.first);
            pq.push(invPair);
            pqSize++;
            if(pqSize > k) {
                pq.pop();
                pqSize--;
            }
        }
        vector<string> kFreqWord;
        kFreqWord.reserve(k);
        while(!pq.empty()) {
            auto invPair = pq.top();
            pq.pop();
            kFreqWord.push_back(invPair.second);
        }
        // reverse(kFreqWord.begin(), kFreqWord.end());
        return kFreqWord;
    }
};
