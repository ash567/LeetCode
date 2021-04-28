class Solution {
    vector<int> getTokens(string s) {
        stringstream sstream(s);
        string token;
        vector<int> intTokens;
        while(getline(sstream, token, '.')) {
            intTokens.push_back(stoi(token));
        }
        return intTokens;
    }
    
    int compareTokens(vector<int> T1, vector<int> T2) {
        int N = min(T1.size(), T2.size()), M = max(T1.size(), T2.size());
        for(int i = N; i < M; i++) {
            if(T1.size() < M)
                T1.push_back(0);
            if(T2.size() < M)
                T2.push_back(0);
        }
        
        for(int i = 0; i < M; i++) {
            if(T1[i] < T2[i])
                return -1;
            else if(T1[i] > T2[i])
                return 1;
        }
        
        if(T1.size() < T2.size())
            return -1;
        else if(T1.size() > T2.size())
            return 1;
        else return 0;
    }
    
public:
    int compareVersion(string version1, string version2) {
        return compareTokens(getTokens(version1), getTokens(version2));
    }
};
