/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<int>> g;
vector<int> visited, disc, low, parent;
vector<pair<int,int>> bridges;
int c;
void bridge_find(int u){
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (int v:g[u]) {
        if (!visited[v]) {
            parent[v]=u;
            bridge_find(v);
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u]){
              //cout << u <<" " << v << endl;
              c++;
            }
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
int main(){
    int n,m,p;
    cin >>n>>m>>p;
    visited.assign(n+1,0);
    disc.assign(n+1,0);
    low.assign(n+1,0);
    parent.assign(n+1,0);
    g.assign(n+1, vector<int>());
    int a, b;
    while(m--){
        cin >>a>> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i=1;i<=n;i++)
        if(!visited[i])
            bridge_find(i);
    cout<<c<<'\n';
    return 0;
}

