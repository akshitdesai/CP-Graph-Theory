/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<bool> visited;
vector<int> parent;
vector<vector<int>> g;
int dfs(int u){
    visited[u]=true;
    int hight=1,x=0;
    //cout<<u<<" ";
    for(int i:g[u])
        if(!visited[i])
            x=max(x,dfs(i));
    return hight+x;
}
int main(){
    int n,root;
    cin >>n;
    parent.assign(n,0);
    visited.assign(n,false);
    g.assign(n, vector<int>());
    for(int i=0;i<n;i++){
        cin>>parent[i];
        if(parent[i]==-1)
            root=i;
        else
            g[parent[i]].pb(i);
    }
    cout<<dfs(root)-1<<'\n';

    return 0;
}
