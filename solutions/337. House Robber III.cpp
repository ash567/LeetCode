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
​
class Solution {
    
    void robHelper(TreeNode* root, int& moneyWithRoot, int& moneyWithoutRoot) {
        if(root == NULL)
            return;
        int moneyWithRootLeftChild, moneyWithoutRootLeftChild, moneyWithRootRightChild, moneyWithoutRootRightChild;
        moneyWithRootLeftChild = moneyWithoutRootLeftChild = moneyWithRootRightChild = moneyWithoutRootRightChild = 0;
        robHelper(root->left, moneyWithRootLeftChild, moneyWithoutRootLeftChild);
        robHelper(root->right, moneyWithRootRightChild, moneyWithoutRootRightChild);
        moneyWithRoot = root->val + moneyWithoutRootLeftChild + moneyWithoutRootRightChild;
        moneyWithoutRoot = max(moneyWithRootLeftChild, moneyWithoutRootLeftChild) + max(moneyWithRootRightChild, moneyWithoutRootRightChild);
        return;
    }
    
public:
    int rob(TreeNode* root) {
        int moneyWithRoot, moneyWithoutRoot;
        moneyWithRoot = moneyWithoutRoot = 0;
        robHelper(root, moneyWithRoot, moneyWithoutRoot);
        return max(moneyWithRoot, moneyWithoutRoot);
    }
};
