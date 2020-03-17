/* Author :- codestromer */




#include<bits/stdc++.h>
using namespace std;
const int V=1000;
int reach[V][V];
int main(){
    int n=4;
    int graph[n][n] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            reach[i][j] = graph[i][j];

    for (int k = 0; k < n; k++){
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < n; j++){
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is 1
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<reach[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
