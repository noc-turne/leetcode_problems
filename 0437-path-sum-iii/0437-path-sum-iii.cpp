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
    int getOne(TreeNode* root, long long curTargetSum) {
        int cnt = 0;
        if(curTargetSum == root->val) cnt ++;
        if(root == nullptr) {
            // cout << root << ' ' << cnt << endl;
            return cnt;
        }
        if(root->left) {
            cnt += getOne(root->left, curTargetSum - root->val);
        }
        if(root->right) {
            cnt += getOne(root->right, curTargetSum - root->val);
        }
        // cout << root->val << ' ' << cnt << ' ' << curTargetSum << endl;
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int res = 0;
        if(root->val == targetSum) res ++;
        if(root->left) {
            res += pathSum(root->left, targetSum);
            // cout << "root " << root->val << endl;
            res += getOne(root->left, targetSum - root->val);
            
        }
        if(root->right) {
            res += pathSum(root->right, targetSum);
            res += getOne(root->right, targetSum - root->val);
        }
        return res;
    }
};