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

    bool judge(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr) return false;
        if(subRoot == nullptr) return false;
        if(root->val == subRoot->val) {
            return judge(root->left, subRoot->left) & judge(root->right, subRoot->right);
        }
        return false;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if(root == nullptr) return false;
        if(subRoot == nullptr) return true;
        bool flag = false;
        if(root->val == subRoot->val) {
            // cout << "value: " << root->val << endl;
            // cout << isSubtree(root->left, subRoot->left) << endl;
            // cout << isSubtree(root->right, subRoot->right) << endl;
            flag = judge(root->left, subRoot->left) & judge(root->right, subRoot->right);
            if(flag == true) return true;
        }
        // cout << "value: " << root->val << ' ' << subRoot->val << endl;
        // cout << isSubtree(root->left, subRoot) << endl;
        // cout << isSubtree(root->right, subRoot) << endl;
        return isSubtree(root->left, subRoot) | isSubtree(root->right, subRoot);

        
    }
};