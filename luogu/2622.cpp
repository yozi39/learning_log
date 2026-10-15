#include<bits/stdc++.h>
using namespace std;

const int N = 12,M = 105;

int n,m;
int a[M][N];

bool st[1<<N];
int dist[1<<N];

int bfs(){
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push((1<<n)-1);
    st[(1<<n)-1]=true;
    dist[(1<<n)-1]=0;
    
    while(q.size()){
        int x = q.front();q.pop();

        for(int i=0;i<m;i++){
            int y=x;
            for(int j = 0;j<n;j++){
                if(a[i][j] == 1 && ((y>>j)&1)){
                    y ^= (1<<j);
                } else if(a[i][j] == -1 && !((y>>j)&1)){
                    y |= (1<<j);
                }
            }
            if(st[y]) continue;
            st[y] = true;
            dist[y] = dist[x] + 1;
            q.push(y);

            if(y==0) return dist[y];
        }
    }

    return -1;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    cout<<bfs();
}