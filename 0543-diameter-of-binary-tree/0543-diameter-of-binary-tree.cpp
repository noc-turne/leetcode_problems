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
    int max_v = 0;

    int depth(TreeNode* root) {
        
        int left = 0;
        int right = 0;
        if(root->left) {
            left = depth(root->left);
        }
        if(root->right) {
            right = depth(root->right);
        }
        max_v = max(max_v, left + right + 1);
        return max(left, right) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_v - 1;
        
    }
};