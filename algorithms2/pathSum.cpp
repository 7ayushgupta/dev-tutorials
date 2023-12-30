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
    map<int, int> d;
    
    bool bfs(TreeNode* root, int sum){
        if( root == NULL)
            return 0;
        if( !(root->left) && !(root->right) && (root->val == sum))
            return 1;
        d[root->val] = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if( u->left){
                d[u->left->val]= d[u->val]+ u->left->val;
                if(!(u->left->left) && !(u->left->right) && d[u->left->val] == sum)
                    return 1;
                q.push(u->left);
            }
            if( u->right){
                d[u->right->val] = d[u->val] + u->right->val;
                if(!(u->right->left) && !(u->right->right) && d[u->right->val]== sum)
                    return 1;
                q.push(u->right);
            }
        }
        return 0;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return bfs(root, targetSum);
        
    }
};