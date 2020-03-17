/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
// Applications:-
// https://www.geeksforgeeks.org/applications-of-depth-first-search/
using namespace std;
vector<bool> visited;
vector<vector<int>> g;
void dfs(int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int i:g[u])
        if(!visited[i])
            dfs(i);
}
int main(){
    int n,t;
    cin >>n>>t;
    visited.assign(n, false);
    g.assign(n, vector<int>());
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }
    dfs(0);
    return 0;
}
