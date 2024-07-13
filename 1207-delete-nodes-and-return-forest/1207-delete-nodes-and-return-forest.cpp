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
    vector<TreeNode*> res = {};
    void myFunc(TreeNode* root, unordered_set<int> hashset) {
        if(root == nullptr) return;
        if(hashset.count(root->val)) {
            if(root->left) {
                myFunc(root->left, hashset);
                if(!hashset.count(root->left->val))
                    res.push_back(root->left);
                else
                    root->left = nullptr;         
            }
            if(root->right) {
                myFunc(root->right, hashset);
                if(!hashset.count(root->right->val))
                    res.push_back(root->right);
                else
                    root->right = nullptr;
            }
        }
        else {
            if(root->left) {
                myFunc(root->left, hashset);
                if(hashset.count(root->left->val))
                    root->left = nullptr;
            }
            if(root->right) {
                myFunc(root->right, hashset);
                if(hashset.count(root->right->val))
                    root->right = nullptr;
            }
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> hashset;
        for(int i=0;i<to_delete.size();i++) {
            hashset.insert(to_delete[i]);
        }
        if(hashset.count(root->val)) {
            if(root->left) {
                if(!hashset.count(root->left->val))
                    res.push_back(root->left);
                myFunc(root->left, hashset);
                root->left = nullptr;
            }
            if(root->right) {
                if(!hashset.count(root->right->val))
                    res.push_back(root->right);
                myFunc(root->right, hashset);
                root->right = nullptr;
            }
        }
        else {
            res.push_back(root);
            myFunc(root, hashset);
        }
        return res;
        
        
    }
};