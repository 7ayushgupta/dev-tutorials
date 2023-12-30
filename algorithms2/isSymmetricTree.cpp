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
    bool isEquivalent(TreeNode* left, TreeNode* right) {
        if (!left || !right) return left == right;
        else return left->val == right->val && isEquivalent(left->left, right->right) && isEquivalent(right->left, left->right);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return isEquivalent(root->left, root->right);
    }
};