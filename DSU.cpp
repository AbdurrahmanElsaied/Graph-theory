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
int main() {
    Fast();
    struct dsu
    {
        int parent[N],sz[N];
    
        dsu(int n)
        {
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                sz[i]=1;
            }
        }
    
        int find(int i)
        {
            return parent[i]==i? i: parent[i] = find(parent[i]);
        }
    
        bool samegroup(int x,int y)
        {
            return find(x)==find(y);
        }
    
        void merge(int x,int y)
        {
            int root1=find(x);
            int root2=find(y);
    
            if(root1==root2) return;
    
            if(sz[root1]>sz[root2])
                swap(root1,root2);
    
            parent[root1]=root2;
            sz[root2]+=sz[root1];
        }
    
        int getsize(int x)
        {
            return sz[find(x)];
        }
    };
    return 0;
}   
