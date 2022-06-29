class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k >= arr.size())
            return arr;
        auto compare = [&arr, x](int i, int j) {
          return make_pair(abs(x - arr[i]), arr[i]) <= make_pair(abs(x - arr[j]), arr[j]);
        };
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;
        if(pos == arr.size()) {
            ans = vector<int>(arr.end() - k, arr.end());
        } else if(pos == 0){
            ans = vector<int>(arr.begin(), arr.begin() + k);
        } else {
            if(compare(pos - 1, pos))
                pos--;
            int l, r;
            l = r = pos; k--;
            while(k--) {
                if(l == 0 and r < ans.size() - 1) {
                    r++;
                }
                else if(r == ans.size() - 1 and l > 0) {
                    l--;
                } else {
                    bool move = compare(l-1, r+1);
                    if(move) {
                        l--; 
                    } else {
                        r++;
                    }
                }
            }
            ans = vector<int>(arr.begin() + l, arr.begin() + r + 1);
