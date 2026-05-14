#include<bits/stdc++.h>
using namespace std;

const int N=55;

char face;
int n,m,xo,yo,xe,ye;

// 0E 1S 2W 3N
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

vector<vector<int>> mp;
int dist[55][55][4];

struct Node{
    int x,y,dir;
};

int getdir(char c){
    if(c=='E') return 0;
    if(c=='S') return 1;
    if(c=='W') return 2;
    if(c=='N') return 3;
    return -1;
}

bool can(int x,int y){
    if(x < 1 || x >= n || y < 1 || y >= m)return false;
    if(mp[x][y]) return false;
    if(mp[x][y + 1]) return false;
    if(mp[x + 1][y]) return false;
    if(mp[x + 1][y + 1]) return false;
    return true;
}

void bfs(int sx,int sy,int sd){
    queue<Node> q;
    q.push({sx,sy,sd});
    dist[sx][sy][sd]=0;

    while(q.size()){
        Node now=q.front();
        q.pop();

        int x=now.x;
        int y=now.y;
        int dir=now.dir;

        // 左转
        int ldir=(dir+3)%4;
        if(dist[x][y][ldir]==-1){
            dist[x][y][ldir]=dist[x][y][dir]+1;
            q.push({x,y,ldir});
        }

        // 右转
        int rdir=(dir+1)%4;
        if(dist[x][y][rdir]==-1){
            dist[x][y][rdir]=dist[x][y][dir]+1;
            q.push({x,y,rdir});
        }

        // 前进 1/2/3
        for(int k=1;k<=3;k++){
            int nx=x+dx[dir]*k;
            int ny=y+dy[dir]*k;

            if(!can(nx,ny)) break;

            if(dist[nx][ny][dir]==-1){
                dist[nx][ny][dir]=dist[x][y][dir]+1;
                q.push({nx,ny,dir});
            }
        }
    }
}

int main(){
    cin>>n>>m;

    mp.assign(n+5, vector<int>(m+5,0));
    memset(dist,-1,sizeof(dist));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }

    cin>>xo>>yo>>xe>>ye;
    cin>>face;

    int sd=getdir(face);

    if(!can(xo,yo) || !can(xe,ye)){
        cout<<-1<<'\n';
        return 0;
    }

    bfs(xo,yo,sd);

    int ans=-1;
    for(int d=0;d<4;d++){
        if(dist[xe][ye][d]!=-1){
            if(ans==-1 || dist[xe][ye][d]<ans){
                ans=dist[xe][ye][d];
            }
        }
    }

    cout<<ans<<'\n';
}