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
    int getLeftHieght(TreeNode* root) {
        if(root->left == NULL)
            return 0;
        else
            return 1 + getLeftHieght(root->left);
    }
    
    int getRightHieght(TreeNode* root) {
        if(root->right == NULL)
            return 0;
        else
            return 1 + getRightHieght(root->right);
    }
    map<int, int> twoPower;
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftHieght = getLeftHieght(root), rightHieght = getRightHieght(root);
        if(leftHieght == rightHieght) {
            if(twoPower.find(leftHieght + 1) == twoPower.end())
                twoPower[leftHieght + 1] = pow(2, leftHieght + 1) - 1;
            return twoPower[leftHieght + 1];
        }
        else 
            return (1 + countNodes(root->left) + countNodes(root->right));
    }
};
