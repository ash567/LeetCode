/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if(r < l)
            return NULL;
        int m = (r-l)/2 + l;
        TreeNode* root = new TreeNode(nums[m]);
        // root->val = nums[m];
        root->left = sortedArrayToBST(nums, l, m - 1);
        root->right = sortedArrayToBST(nums, m + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};
