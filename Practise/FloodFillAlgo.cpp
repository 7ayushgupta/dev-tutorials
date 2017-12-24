#include<bits/stdc++.h>
using namespace std;
bool visited[11][11];
int matrix[11][11];
int n,m;

bool dfs(int x,int y,int n,int m){

if(x>n || y>m)
return false;
if(x<0 || y<0)
return false;
if(x==n && y==m)
return true;

if(visited[x][y]==true)
return false;
visited[x][y]=true;
if(matrix[x][y]==0)
return false;

if(dfs(x+1,y,n,m)==true)
return true;

if(dfs(x,y+1,n,m)==true)
return true;

if(dfs(x-1,y,n,m)==true)
return true;

if(dfs(x,y-1,n,m)==true)
return true;

return false;

}

int main(){
for(int i=0;i<11;i++){
for(int j=0;j<11;j++)
visited[i][j]=false;
}
cin>>n>>m;

for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++)
cin>>matrix[i][j];
}

if(dfs(1,1,n,m))
cout<<"Yes";
else 
cout<<"No";

return 0;
}
