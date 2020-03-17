/* Author :- codestromer */





#include<bits/stdc++.h>
#define pb push_back
//O(V+E) --> time complexity
// USING --> Kosaraju's Stronly connected Components Algo
//If there exist mother vertex (or vertices),
//then one of the mother vertices is
//the last finished vertex in DFS.
using namespace std;
vector<vector<int>> g;
void dfs(int u,vector<bool> &visited){
    visited[u]=true;
    //cout<<u<<" ";
    for(int i:g[u])
        if(!visited[i])
            dfs(i,visited);
}
int findmother(int n){
    vector<bool> visited(n,0);
    int v=0;
    //find last visited vertex
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited);
            v=i;
        }
    }
    //check is it really mother vertex or not
    fill(visited.begin(),visited.end(),false);
    dfs(v, visited);
    for(int i=0;i<n;i++)
        if(!visited[i])
            return -1;
    return v;
}
int main(){
    int n,t;
    cin >>n>>t;
    g.assign(n, vector<int>());
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }
    cout<<findmother(n);
    return 0;
}
