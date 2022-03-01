//c191040@ugrad.iiuc.ac.bd
//bfs
//
#include<bits/stdc++.h>
#define WHITE 1
#define BLACK 3
#define GREY 2
using namespace std;

int adj[100][100];
int color[100];
int node,edge;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void bfs_visit(int x){
    color[x] = GREY;
    
   // neighour ber kore shey neighour er nodegulo visit korbo
    for(int i = 0; i < node;i++){
        if(adj[x][i] == 1)
        {
            if(color[i] == WHITE){
                bfs_visit(i);  
            }
        }
    }

    color[x] = BLACK;
}

void bfs()
{
    for(int i = 0; i < node;i++){
        color[i] = WHITE;
    }
    for(int i = 0;i < node; i++){
        if(color[i] == WHITE){
            bfs_visit(i);
        }
    }
}




int main()
{
    init_code();
    fastIO();

    int n1,n2;
    cin>>n1>>n2;

    adj[n1][n2] = 1;
    adj[n2][n1] = 1;

    bfs();
}