/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
// Applications:-
// https://www.geeksforgeeks.org/applications-of-breadth-first-traversal/

vector<vector<int>> g;
vector<string> colour;
vector<int> d,p;

void bfs(int u){
    queue<int> q;
    q.push(u);

    d[u] = 0;
    colour[u] = "green";

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for(int i:g[f]){
            if (colour[i] == "white"){
                colour[i] = "green";
                d[i] = d[f] + 1;
                p[i] = u;
                q.push(i);
            }
        }
    }
    colour[u] = "dark_green";
}
int main(){
    int n,t;
    cin >>n>>t;

    g.assign(n, vector<int>());
    colour.assign(n, "white");
    d.assign(n, 0);
    p.assign(n, -1);

    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }

    for (int i = 0; i < n; i++)
        if(colour[i]=="white")
            bfs(i);
    return 0;
}
