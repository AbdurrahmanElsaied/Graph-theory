#include <bits/stdc++.h>
using namespace std;
void A() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
}
const int N=1e5+5;
bool vis[N]={};
vector<int> adj[N];
void dfs(int node) {
    cout << node << " ";
    vis[node]=true;
    for(int i=0;i<adj[node].size();i++) {
        int child=adj[node][i];
        if(!vis[child]) dfs(child);
    }
}
int n,m;
int main() {
    A();
    cin >> n >> m;
    for(int i=0;i<m;i++) {
       int u,v;
       cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
     }
     dfs(1);

    return 0;
}