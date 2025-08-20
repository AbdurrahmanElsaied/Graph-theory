#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x)  (int) x.size()
#define oo INT_MAX
#define ooL LLONG_MAX
#define mod 1000000007
#define fix(x, m) (((x) % (m) + (m)) % (m))
#define cin(v) for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';
void A() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("Input.txt.txt", "r", stdin);
		freopen("Output.txt", "w", stdout);
	#else
		//freopen("splits.in", "r", stdin);
	#endif
}
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};

const int N = 1e5 + 5;
vector<int> adj[N];
void BFS(int root) {
		vector<int> d(N, oo);
		queue<int> q;
		q.push(root), d[root] = 0;
		while(!q.empty()) {
			int v=q.front();
			q.pop();

			for (int i=0;i<adj[v].size();++i) {
				int u=adj[v][i];
				if (d[u] == oo) {
					cout << u;
					q.push(u);
					d[u] = d[v]+1;
				}
			}
		}
}


signed main(){
	A();
	int n,m;cin >> n >> m;
	for(int i=1;i<=m;++i) {
		int a,b;cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	BFS(1);
	return 0;
}