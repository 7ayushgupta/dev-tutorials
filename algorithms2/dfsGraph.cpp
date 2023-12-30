void dfs(int vertex, vector<int> adj[], bool visited[],vector<int> &res)
{
   visited[vertex] = true;
   res.push_back(vertex);
   for(int child:adj[vertex])
   {
       if(visited[child]) continue;
       
       dfs(child,adj,visited,res);
   }
   return;
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
   // Code here
   bool visited[V];
   vector<int> res;
   for(int i=0;i<=V;i++)
   {
       visited[i] = false;
   }
   dfs(0,adj,visited,res);
   return res;
   zo
}