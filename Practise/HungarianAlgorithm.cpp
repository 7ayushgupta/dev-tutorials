#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9+7;
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;cin>>t;
	rep(aa,t){
		int n,m;cin>>m>>n;
		int a[n+1][m+1];
		rep(j,m) rep(i,n) cin>>a[i+1][j+1];
		vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
		for (int i=1; i<=n; ++i) {
			p[0] = i;
			int j0 = 0;
			vector<int> minv (m+1, INF);
			vector<char> used (m+1, false);
			do {
				used[j0] = true;
				int i0 = p[j0],  delta = INF,  j1;
				for (int j=1; j<=m; ++j)
					if (!used[j]) {
						int cur = a[i0][j]-u[i0]-v[j];
						if (cur < minv[j])
							minv[j] = cur,  way[j] = j0;
						if (minv[j] < delta)
							delta = minv[j],  j1 = j;
					}
				for (int j=0; j<=m; ++j)
					if (used[j])
						u[p[j]] += delta,  v[j] -= delta;
					else
						minv[j] -= delta;
				j0 = j1;
			} while (p[j0] != 0);
			do {
				int j1 = way[j0];
				p[j0] = p[j1];
				j0 = j1;
			} while (j0);
		}
		int cost = -v[0];
		cout<<cost<<endl;
	}
 
	return 0;
}
