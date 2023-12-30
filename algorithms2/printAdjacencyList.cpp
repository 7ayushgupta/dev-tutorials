vector<vector<int>> printGraph(int V, vector<int> adj[]) {
    // Code here
    vector<vector<int> > v(V);
    for(int i = 0; i<V; i++){
        v[i].push_back(i);
        for(auto x: adj[i])
            v[i].push_back(x);
    }
    return v;
}