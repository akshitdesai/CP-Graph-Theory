/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n;
//Given a graph G and an integer K,
//K-cores of the graph are connected components
//that are left after
//all vertices of degree less than k have been removed
vector<bool> visited;
vector<vector<int>> g;
bool dfs(int u,vector<bool> &visited,
            vector<int> &vDegree, int k){
    visited[u]=true;
    for(int i:g[u]){
        if(vDegree[u]<k)
            vDegree[i]--;
        if(!visited[i])
            if(dfs(i,visited,vDegree,k))
                vDegree[i]--;
    }
    return (vDegree[u]<k);
}
void printKCores(int k){
    vector<bool> visited(n,false);
    vector<bool> processed(n,false);
    vector<int> vDegree(n);
    int mindeg = INT_MAX;
    int startvertex;
    for (int i=0; i<n; i++){
        vDegree[i]=g[i].size();
        if (vDegree[i] < mindeg){
            mindeg = vDegree[i];
            startvertex=i;
        }
    }
    dfs(startvertex,visited,vDegree,k);
    for (int i=0;i<n;i++)
        if (visited[i] == false)
            dfs(i,visited,vDegree,k);

    //printing
    cout << "\nK-Cores :";
    for (int v=0; v<n; v++){
        if (vDegree[v] >= k)
        {
            cout << "\n[" << v << "]";
            list<int>::iterator itr;
            for (int i:g[v])
                if (vDegree[i]>=k)
                    cout<<" -> "<<i;
        }
    }
}
int main(){
    int t;
    cin >>n>>t;
    visited.assign(n, false);
    g.assign(n, vector<int>());
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    printKCores(3);
    return 0;
}
