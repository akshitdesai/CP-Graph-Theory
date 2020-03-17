/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<bool> visited;
vector<vector<int>> g;
int countc[2]={0};
void findedges(int u,int color){
    visited[u]=true;
    countc[1-color]++;
    for(int i:g[u])
        if(!visited[i])
            findedges(i,1-color);
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
    findedges(0,1);
    cout<<countc[0]*countc[1]-(n-1);
    return 0;
}
