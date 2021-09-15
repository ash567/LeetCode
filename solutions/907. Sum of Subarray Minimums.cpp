// Some of the learnings:
​
// Sentinels:
// Set initial values of left to be -1 and right to be arr.size()
// As they represent the first element on the left which is smaller than current element. If in the entire left array, current element is the lowest, then we assume that there exist an INT_MIN at the before the 0th index
​
// Now when there are dupilates
​
​
// consider an array 
// A = [2, 2, 3]
    
// arrays where A[0] is minimum [0-2], and where A[1] is minimum [0-2], [1-2]
​
// In order not to get duplicates, for any element, we will consider an element A[j] to be the previous less element of A[i] only until A[i] > A[j] (Note j < i by definition)
// That means for Array A[1] the array [0-2] wont be a valid answer.
// Important Takeaway: Stop at A[j] <= A[i] iff we impose a strict A[stack.top()] > A[i] condition in the loop, But at the time of considering next less element, stop at A[j] < A[i] iff A[stack.top()] > A[i]
​
// What this does is, we are going as right as possible, but we go minimal left that we have to.
// This eliminates the duplicates 
​
class Solution {
    const long MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size(), -1), right(arr.size(), arr.size());
        stack<int> mis;
        for(int i = 0; i < arr.size(); i++) {
            while(!mis.empty() && arr[mis.top()] > arr[i]) {
                right[mis.top()] = i;
                mis.pop();
            }
            left[i] = mis.empty() ? -1 : mis.top();
            mis.push(i);
        }
        long countSum = 0;
        for(int i = 0; i < arr.size(); i++) {
            countSum += ((long) arr[i]) * (i - left[i]) * (right[i] - i);
            countSum %= MOD;
        }
        return countSum;
    }
};
