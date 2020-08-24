#include<lucky.h>


const int mxN=5e5;
int n, a, b, s[mxN], ca[mxN], cb[mxN];;
ld ans;
vector<int> adj[mxN];
//unordered_map<int, int> mpa[mxN], mpb[mxN];

void dfs(int u=0, int p=-1, int d=0) {
	
	ll la=ca[d%a], lb=cb[d%b]; 
	++ca[d%a], ++cb[d%b]; 
	EACH(v, adj[u])
		if(v^p)
			dfs(v, u, d+1);
	//dbg(mpa[u][d%a], mpb[u][d%b]);
	ll na=n-(ca[d%a]-la), nb=n-(cb[d%b]-lb); write(na);
	//dbg(na, nb);
	ans+=1.0-na*nb/((ld)n)/n;

}

void solve() {
	ans=0;
	read(n, a, b);
	FOR(i, 1, n) {
		int p;
		read(p), --p;
		adj[p].pb(i);
		adj[i].pb(p);
	}
	memset(ca, 0, 4*n);
	memset(cb, 0, 4*n);
	dfs();
	FOR(n)
		adj[i].clear();
	cout << fixed << setprecision(9);
	print(ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	read(t);
	FOR(t) {
		write("Case #", i+1, ": ");
		solve();
	}
}