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
    
    void delNodesHelper(TreeNode* root, int headPush, const set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if(root == NULL)
            return;
        TreeNode *left = root->left, *right = root->right;
        if(left != NULL && toDeleteSet.find(left->val) != toDeleteSet.end())
            root->left = NULL;
        if(right != NULL && toDeleteSet.find(right->val) != toDeleteSet.end())
            root->right = NULL;
        if(toDeleteSet.find(root->val) != toDeleteSet.end()) {
            delete(root);
            headPush = 1;
        } else {
            if(headPush == 1)
                forest.push_back(root);
            headPush = 0;
        }
        delNodesHelper(left, headPush, toDeleteSet, forest);
        delNodesHelper(right, headPush, toDeleteSet, forest);
        return;
    }
​
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        delNodesHelper(root, 1, toDeleteSet, forest);
        return forest;
    }
};
