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
    int depth(TreeNode* root) {
        int left = 0;
        int right = 0;
        if(root->left) {
            left = depth(root->left);
        }
        if(root->right) {
            right = depth(root->right);
        }
        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        // cout << root->val << ' ' << left << ' ' << right << endl;
        return 1 + max(left, right);
            
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int res = 0;
        res = depth(root);
        if(res == -1) return false;
        return true;
 
    }
};