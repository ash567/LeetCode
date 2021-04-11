class Solution {
​
    void mergeSort(vector<pair<int, int>>& valueIndex, int beg, int end, vector<int>& countSmall) {
        if(beg >= end -1)
            return;
        int mid = beg + (end - beg)/2;
        mergeSort(valueIndex, beg, mid, countSmall);
        mergeSort(valueIndex, mid, end, countSmall);
        vector<pair<int, int>> sortedArr;
        int rightInd = mid, leftInd = beg, countSmaller = 0;
        while(rightInd < end && leftInd < mid) {
            if(valueIndex[leftInd].first <= valueIndex[rightInd].first) {
                sortedArr.push_back(valueIndex[leftInd]);
                countSmall[valueIndex[leftInd].second] += countSmaller;
                leftInd++;
            } else {
                sortedArr.push_back(valueIndex[rightInd]);
                countSmaller++;
                rightInd++;
            }
        }
        while(leftInd < mid) {
            sortedArr.push_back(valueIndex[leftInd]);
            countSmall[valueIndex[leftInd].second] += countSmaller;
            leftInd++;
        }
        while(rightInd < end) {
            sortedArr.push_back(valueIndex[rightInd]);
            rightInd++;
        }
        for(int i = 0; i < sortedArr.size(); i++) {
            valueIndex[beg + i] = sortedArr[i];
        }
        return;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> countSmall(N, 0);
        if(N == 0)
            return countSmall;
        vector<pair<int, int>> valueIndex(N);
        for(int i = 0; i < N; i++)
            valueIndex[i] = make_pair(nums[i], i);
