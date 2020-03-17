/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<vector<pair<int,int>>> g;
vector<int> dist;

void dijkstra(int src){
    //weight,vertex
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(pair<int,int> i:g[u]){
            int weight=i.first;
            int v=i.second;
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
}
int main(){
    int n,t;
    cin>>n>>t;
    g.assign(n,vector<pair<int,int>>());
    dist.assign(n,INT_MAX);
    while(t--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].pb({w,b});
        g[b].pb({w,a});
    }
    int src;
    cin>>src;
    dijkstra(src);
    for(int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<'\n';
}
