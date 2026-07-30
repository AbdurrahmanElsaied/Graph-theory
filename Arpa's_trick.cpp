#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fix(x, m) (((x) % (m) + (m)) % (m))
void Fast(){    ios::sync_with_stdio(false);  cin.tie(0);cout.tie(0);}
const int MOD = 1e9+7;
const int N=2e5+10;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
struct ArpaRMQ
{
    int parent[N], ans[N];
    vector<pair<int,int>> query[N];
    stack<int> st;

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void init(int n)
    {
        while(!st.empty())
            st.pop();

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            query[i].clear();
        }
    }

    void solve(vector<int> &a, int n)
    {
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && a[st.top()] > a[i])
            {
                parent[st.top()] = i;
                st.pop();
            }
            st.push(i);
            for(auto [l, id] : query[i])
                ans[id] = a[find(l)];
        }
    }

};
int main() {
    Fast();
    int n;
    cin >> n;
    // For Range query (offline)
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ArpaRMQ rmq;
    rmq.init(n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;      
        rmq.query[r].push_back({l, i});
    }
    rmq.solve(a, n);
    for(int i = 0; i < q; i++)
        cout << rmq.ans[i] << '\n';
    return 0;
}   
