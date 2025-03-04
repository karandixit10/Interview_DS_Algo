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
    TreeNode* dfs(TreeNode* root, int val, int depth, int curr){
        if(!root) return NULL;

        if(curr == depth-1){
            TreeNode* lTemp = root->left;
            TreeNode* rTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = lTemp;
            root->right->right = rTemp;
            return root;
        }

        root->left  = dfs(root->left, val, depth, curr+1);
        root->right = dfs(root->right, val, depth, curr+1);
        
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return dfs(root, val, depth, 1);
    }
};