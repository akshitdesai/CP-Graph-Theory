/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
// Applications:-
// https://www.geeksforgeeks.org/applications-of-breadth-first-traversal/
vector<bool> visited;
vector<vector<int>> g;
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for(int i:g[f]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
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
    for (int i = 0; i < n; i++)
        if(!visited[i])
            bfs(i);
    return 0;
}
