#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 1e9+7;
const int N=3e5+5;
const int dx[8] = {1, 0, 0, -1, 1, 1, -1, -1}, dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
vector<int> adj[N];
int BFS(int s,vector<int> &d)
{
    queue<int> q;
    d.assign(N,-1);
    vector<bool>vis(N,false);
    d[s]=0;vis[s]=1;
    q.push(s);int last=s;
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        for (int i:adj[cur])
        {
            if (!vis[i])
            {
                vis[i]=1;
                d[i]=d[cur]+1;
                q.push(i);
            }
        }
        last=cur;
    }
    return last;
}
int main(){
    Fast();
        int n;cin >> n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dx,dy;
    int x=BFS(1,dx);
    int y=BFS(x,dx);
    int ans = dx[y];
    int z=BFS(y,dy);
    for (int i=1;i<=n;i++)cout << max(ans,max(dx[i],dy[i])+1) << '\n';
    return 0;
}