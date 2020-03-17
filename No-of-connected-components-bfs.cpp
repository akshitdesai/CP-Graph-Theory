/* Author :- codestromer */




#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> vis;
void dfs(int i){
    vis[i]=true;
    for(int k:g[i])
        if(!vis[k])
            dfs(k);
}
int main(){
    int n,m,k,u,v,count=0;
    cin>>n>>m>>k;
    g.assign(n,vector<int>());
    vis.assign(n,false);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i);
        }
    }
    cout<<count<<'\n';
    return 0;
}
