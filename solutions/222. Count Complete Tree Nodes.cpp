 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int, int> twoPower;
​
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
    
    int countNodes(TreeNode* root, int leftHieght, int rightHieght) {
        if(root == NULL)
            return 0;
        else if(root->left == NULL)
            return 1;
        else if(root->right == NULL)
            return 2;
        else if(leftHieght == rightHieght) {
            if(twoPower.find(leftHieght + 1) == twoPower.end())
                twoPower[leftHieght + 1] = pow(2, leftHieght + 1) - 1;
            return twoPower[leftHieght + 1];
        }
        else 
            return (1 + countNodes(root->left, leftHieght - 1, getRightHieght(root->left)) + countNodes(root->right, getLeftHieght(root->right), rightHieght - 1));
    }
​
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        else if(root->left == NULL)
            return 1;
        else if(root->right == NULL)
            return 2;
        else 
            return countNodes(root, getLeftHieght(root), getRightHieght(root));
    }
};
