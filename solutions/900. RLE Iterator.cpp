class RLEIterator {
private:
    vector<int> seq;
    vector<long long> cumulativeSize;
    long long currSum;
    int currIdx;
    
public:
    RLEIterator(vector<int>& A) {
        long long cumSum = 0;
        for(int i = 0; i < A.size(); i = i + 2) {
            if(A[i] == 0)
                continue;
            seq.push_back(A[i+1]);
            cumSum += A[i];
            cumulativeSize.push_back(cumSum);
        }
        currSum = 0;
        currIdx = 0;
    }
    
    int next(int n) {
        currSum += n;
        while(currIdx < cumulativeSize.size() && cumulativeSize[currIdx] < currSum) {
            currIdx++;
        }
        if(currSum >= cumulativeSize[cumulativeSize.size()-1] || currIdx >= cumulativeSize.size())
            return -1;
        return seq[currIdx];
    }
};
​
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
