// class Solution {
//     int countSmaller(vector<int>& arr, float r, int& a, int&b) {
//         float maxRatio = 0.0;
//         int j = 1, i = 0;
//         int count = 0;
//         // cout << "Curr Ratio: " << r << endl;
//         for(; j < arr.size(); j++) {
//             float currRatio = (float) arr[i] / (float) arr[j];
//             while(i < j and currRatio <= r) {
//                 if(maxRatio < currRatio) {
//                     a = arr[i]; b = arr[j];
//                     maxRatio = currRatio;
//                 }
//                 i++;
//                 currRatio = (float) arr[i] / (float) arr[j];
//             }
//             // cout << "j: " << j << ", i: " << i << endl;
//             count += i;
//         }
//         return count;
//     }
    
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         float left = 0.0, right = 1.0, eps = 1e-9;
//         int a, b;
//         while(left < right) {
//             a = b = 1;
//             float mid = left + (right - left) / 2.0;
//             int counts = countSmaller(arr, mid, a, b);
//             // cout << mid << " " << counts << endl;
//             if(counts == k) {
//                 break;
//             } else if(counts > k) {
//                 right = mid;
//             } else {
//                 left = mid + eps;
//             }
//         }
//         return vector<int>({a, b});
//     }
// };
​
​
class Solution {
    
