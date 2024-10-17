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

    bool myFunc(TreeNode* root, long long upper_bound, long long lower_bound) {

        long long cur_val = root->val;
        if(cur_val >= upper_bound || cur_val <= lower_bound) return false;
        bool flag1, flag2;
        if(root->left) {
            flag1 = myFunc(root->left, cur_val, lower_bound);
            if(flag1 == false) return false;
        }
        if(root->right) {
            flag2 = myFunc(root->right, upper_bound, cur_val);
            if(flag2 == false) return false;
        }

        return true;

    }

    bool isValidBST(TreeNode* root) {
        long long upper_bound = 1e10;
        long long lower_bound = -1e10;
        bool flag1, flag2;
        if(root->left) {
            flag1 = myFunc(root->left, root->val, lower_bound);
            if(flag1 == false) return false;
        }
        if(root->right) {
            flag2 = myFunc(root->right, upper_bound, root->val);
            if(flag2 == false) return false;
        }

        return true;
    }
};