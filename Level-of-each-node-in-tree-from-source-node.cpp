/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<bool> visited;
vector<vector<int>> g;
vector<int> nodeLevel;

void dfs(int u,int level){
    visited[u]=true;
    nodeLevel[u]=level;
    cout<<u<<" ";
    for(int i:g[u])
        if(!visited[i])
            dfs(i,level+1);
}
int main(){
    int n,t;
    cin >>n>>t;
    visited.assign(n, false);
    nodeLevel.assign(n, 0);
    g.assign(n, vector<int>());
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }
    dfs(0,0);
    cout<<"\nLevel of all node\n";
    for(int i=0;i<n;i++)
        cout<<i<<" "<<nodeLevel[i]<<'\n';
    return 0;
}
