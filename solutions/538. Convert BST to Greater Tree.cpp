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
    void convertBST(TreeNode* root, int& rightSum) {
        if(root == NULL)
            return;
        convertBST(root->right, rightSum);
        rightSum += root->val;
        root->val = rightSum;
        convertBST(root->left, rightSum);
        return;
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int rightSum = 0;
        convertBST(root, rightSum);
        return root;
    }
};
