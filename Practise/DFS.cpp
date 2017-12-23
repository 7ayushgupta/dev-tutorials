#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
bool visited[100005] = { false };
int ans = 0;
void dfs(int s){
visited[s] = true;
ans++;
for(int i = 0; i < adj[s].size(); ++i)
if(visited[adj[s][i]] == false)
dfs(adj[s][i]);
}

int main(){
int n, e, x, y;
cin >> n >> e;
for(int i = 0; i < e; i++){
cin >> x >> y;
adj[x].push_back(y); 
adj[y].push_back(x); 
}
int sd; 
cin >> sd;
dfs(sd);
cout << (n - ans);
return 0;
}
