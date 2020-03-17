/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<bool>> visited;
vector<vector<int>> g;
void dfs(int s,int v){
    visited[s][v]=true;
    for(int i:g[v])
        if(!visited[s][i])
            dfs(s,i);
}
int main(){
    int n,t;
    cin >>n>>t;
    g.assign(n, vector<int>());
    visited.assign(n, vector<bool>());
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            visited[i][j]=false;
    for(int i=0;i<n;i++)
        dfs(i,i);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<visited[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}

