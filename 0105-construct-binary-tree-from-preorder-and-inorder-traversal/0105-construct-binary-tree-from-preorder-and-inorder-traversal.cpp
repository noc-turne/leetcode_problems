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

    TreeNode* myFunc(vector<int> &preorder, unordered_map<int,int> &hashmap, int inorder_start, int inorder_end, int preorder_root) {
        if(inorder_end < inorder_start) return nullptr;
        // cout << inorder_start << ' ' << inorder_end << ' ' << preorder_root << endl;
        int root_val = preorder[preorder_root];
        TreeNode* root = new TreeNode(root_val);
        int split = hashmap[root_val];
        int left_tree_len = split - inorder_start;
        TreeNode* left = myFunc(preorder, hashmap, inorder_start, split - 1, preorder_root + 1); 
        TreeNode* right = myFunc(preorder, hashmap, split + 1, inorder_end, preorder_root + 1 + left_tree_len);
        root->left = left;
        root->right = right;
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<inorder.size();i++) {
            hashmap[inorder[i]] = i;
        }
        if(preorder.size() == 0) return nullptr;
        TreeNode* root = myFunc(preorder, hashmap, 0, inorder.size() - 1, 0);
        return root;




        
    }
};