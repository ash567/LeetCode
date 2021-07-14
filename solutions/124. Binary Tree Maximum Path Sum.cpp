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
    int helper(TreeNode* root, int& maxPathSum) {
        if(root == NULL)
            return 0;
        int leftVal = helper(root->left, maxPathSum), rightVal = helper(root->right, maxPathSum);
        maxPathSum = max(maxPathSum, max(leftVal, 0) + root->val + max(rightVal, 0));
        return root->val + max(0, max(leftVal, rightVal));
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        helper(root, maxPathSum);
        return maxPathSum;
    }
};
