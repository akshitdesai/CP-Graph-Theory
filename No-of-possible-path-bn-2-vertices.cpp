/* Author :- codestromer */




#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<bool> visited;
vector<vector<int>> g;
void dfs(int s,int d,int &pathcount){
    visited[s]=true;
    if(s==d)
        pathcount++;
    else{
        for(int i:g[s])
            if(!visited[i])
                dfs(i,d,pathcount);
    }
    visited[s]=false;
}
int main(){
    int n,t;
    cin >>n>>t;
    g.assign(n, vector<int>());
    visited.assign(n,false);
    int a, b;
    while(t--){
        cin >>a>> b;
        g[a].pb(b);
    }
    int s,d;
    cin>>s>>d;
    int pathcount=0;
    dfs(s,d,pathcount);
    cout<<pathcount<<'\n';
    return 0;
}


