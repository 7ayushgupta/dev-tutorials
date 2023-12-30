vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<int> vis(V, 0);
        
        if(!vis[0]){
            queue<int> q;
            q.push(0);
            vis[0] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        return bfs;
        
    }

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int sz=q.size();
           vector<int>v;
           while(sz--){
               TreeNode * f=q.front();
               v.push_back(q.front()->val);
               q.pop();
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);
    
           }
           ans.push_back(v);
        }
        return ans;
    }
};