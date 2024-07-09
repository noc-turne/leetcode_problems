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
        int res = 1;
        if(root->left) {
            res = max(res, depth(root->left) + 1);
        }
        if(root->right) {
            res = max(res, depth(root->right) + 1);
        }
        return res;
            
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int depth1 = 0, depth2 = 0;
        if(root->left) {
            depth1 = depth(root->left);
        }
        if(root->right) {
            depth2 = depth(root->right);
        }
        // cout << depth1 << depth2 << endl;
        if(abs(depth1 - depth2) <= 1) {
            if(isBalanced(root->left) && isBalanced(root->right)) return true;
            else return false;
        }
        else return false;
 
    }
};