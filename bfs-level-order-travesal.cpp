/* Author :- codestromer */



#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;
void bfs(int i){
    queue<int> q;
    vis[i]=1;
    q.push(i);
    //int count=0;
    int flag=1;
    while(!q.empty()){
        //count++;
        int qs = q.size();
        for(int j=0;j<qs;j++){
            int top = q.front();
            vis[top]=1;
            q.pop();
            cout<<top<<" ";
            for(int x:g[top]){
                if(vis[x])continue;
                q.push(x);
                vis[x]=1;
            }
        }
        cout<<'\n';
    }
    //return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        vis.assign(n+1,0);
        g.assign(n+1,vector<int>());
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        cout<<"Level-vise node\n";
        bfs(1);
        cout<<'\n';//<<bfs(1)<<'\n';
    }
}
