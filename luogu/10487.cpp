#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

#define qp '\n'

const int N=805;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int n,m;
char g[N][N];
PII boy,girl,ghost[2];
queue<PII> q[2];
bool st[2][N][N];

bool check(int x,int y,int step){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(g[x][y]=='X') return false;

    for(int i=0;i<2;i++){
        int d=abs(x-ghost[i].first)+abs(y-ghost[i].second);
        if(d<=2*step) return false;
    }

    return true;
}

bool extend(int a,int b,int k,int step){
    while(k--){
        int sz=q[a].size();

        while(sz--){
            auto t=q[a].front();
            q[a].pop();

            int x=t.first,y=t.second;

            if(!check(x,y,step)) continue;

            for(int i=0;i<4;i++){
                int nx=x+dx[i],
                    ny=y+dy[i];

                if(!check(nx,ny,step)) continue;
                if(st[a][nx][ny]) continue;

                st[a][nx][ny]=true;

                if(st[b][nx][ny]) return true;

                q[a].push({nx,ny});
            }
        }
    }

    return false;
}

int bfs(){
    while(q[0].size()) q[0].pop();
    while(q[1].size()) q[1].pop();
    memset(st,0,sizeof st);

    q[0].push(boy);
    q[1].push(girl);

    st[0][boy.first][boy.second]=true;
    st[1][girl.first][girl.second]=true;

    int step=0;

    while(q[0].size() && q[1].size()){
        step++;

        if(extend(0,1,3,step) || extend(1,0,1,step))
            return step;
    }

    return -1;
}

int main(){
    int T;
    cin>>T;

    while(T--){
        cin>>n>>m;

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];

                if(g[i][j]=='M'){
                    boy={i,j};
                }
                else if(g[i][j]=='G'){
                    girl={i,j};
                }
                else if(g[i][j]=='Z'){
                    ghost[cnt++]={i,j};
                }
            }
        }

        cout<<bfs()<<qp;
    }

    return 0;
}