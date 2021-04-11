class Solution {
    string decodeStringHelper(string &s, int depth, int& nextScan) {
        // cout << nextScan << endl;
        if(nextScan >= s.size())
            return "";
        string repString = "", headString = "";
        int j = nextScan;
        while(j < s.size() && isalpha(s[j]))
            j++;
        headString = s.substr(nextScan, j - nextScan);
        nextScan = j;
        while(j < s.size() && isdigit(s[j]))
            j++;
        if(nextScan != j) {
            int rep = stoi(s.substr(nextScan, j - nextScan));
            nextScan = j+1;
            string currString = "";
            while(nextScan < s.size() && s[nextScan] != ']')
                currString += decodeStringHelper(s, depth + 1, nextScan);
            while(rep--)
                repString += currString;
            nextScan++; // for eliminating the ]
        }
        headString = headString +  repString;
        // cout << headString << endl;
        if(depth == 0)
            return headString + decodeStringHelper(s, depth, nextScan);
        else
            return headString;
    }
    
public:
    string decodeString(string s) {
        int nextScan = 0;
        return decodeStringHelper(s, 0, nextScan);
    }
};
