#include<bits/stdc++.h>
#define ll long long int
#define vii  vector<int>::iterator 
#define vli  vector<ll>::iterator 
#define vi  vector<int> 
#define vl  vector<ll> 
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define MOD 1000000007
#define in cin>>
#define i2(x,y) cin>>x>>y
#define i3(x,y,z) cin>>x>>y>>z
#define os(x) cout<<x<<' '
#define on(x) cout<<x<<endl
#define o2(x,y) cout<<x<<' '<<y<<endl
#define o3(x,y,z) cout<<x<<' '<<y<<' '<<z<<endl
#define pn cout<<endl
#define F first
#define S second
#define for_it(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define op(X) cout<<X.F<<" "<<X.S<<" ";
#define opn(X) cout<<X.F<<" "<<X.S<<endl;
#define SET(X,Y) memset(X,Y,sizeof(X))
using namespace std;
int edge[300][300]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	int t,i,j,k,n,m,a,b,c;	
	i2(n,m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			edge[i][j] = i==j?0:1e8;
	while(m--)
	{
		i3(a,b,c);
		edge[a][b] = min(edge[a][b],c);
		edge[b][a] = min(edge[b][a],c);
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(edge[i][k] + edge[k][j] < edge[i][j])
					edge[i][j] = edge[i][k] + edge[k][j];
			}
	}
	int ans = 0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ans = max(ans,edge[i][j]);
	on(ans);
 
} 
