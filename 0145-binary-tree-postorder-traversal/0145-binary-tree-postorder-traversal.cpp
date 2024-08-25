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
private:
    void postorderTraversalHelper(TreeNode* currNode,vector<int>& result){
        if(!currNode) return;
        postorderTraversalHelper(currNode->left, result);
        postorderTraversalHelper(currNode->right, result);
        result.push_back(currNode->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
    }
};