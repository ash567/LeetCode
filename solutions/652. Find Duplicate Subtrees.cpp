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
private:
    int hashCode;
    unordered_map<string, int> stringToHash;
    unordered_set<TreeNode*> nodeSet;
    unordered_set<int> hashRecord;
        
    int findDuplicateSubtreesHelper(TreeNode* root) {
        if(root == NULL)
            return -1;
        else {
            int leftHash, rightHash;
            leftHash = findDuplicateSubtreesHelper(root->left);
            rightHash = findDuplicateSubtreesHelper(root->right);
            string stringHash = to_string(leftHash) + '*' + to_string(root->val) + '*' + to_string(rightHash);
            if(stringToHash.find(stringHash) == stringToHash.end()) {
                stringToHash[stringHash] = hashCode;
                hashCode++;
            } else {
                if(hashRecord.find(stringToHash[stringHash]) ==  hashRecord.end()) {
                    nodeSet.insert(root);
                }
                hashRecord.insert(stringToHash[stringHash]);
            }
            return stringToHash[stringHash];
        }
    }
        
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        hashCode = 0;
        findDuplicateSubtreesHelper(root);
        vector<TreeNode*> duplicateSubtreeNodes(nodeSet.begin(), nodeSet.end());
