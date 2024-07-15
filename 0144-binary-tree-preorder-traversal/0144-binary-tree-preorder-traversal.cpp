/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    void myFunc(TreeNode* root) {
        if(root) {
            res.push_back(root->val);
            myFunc(root->left);
            myFunc(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        myFunc(root);
        return res;
        
        
    }
};