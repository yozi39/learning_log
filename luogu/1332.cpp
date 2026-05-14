#include<bits/stdc++.h>//多元bfs区别就是先将所以起点加入队列中
using namespace std;

const int N=1e5+10;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,a,b;
int mapp[505][505];

struct P1332{
    int x,y;
}ap[N],bp[N];

queue<P1332> q;

void bfs(){
    while(q.size()){
        auto tmp=q.front();
        q.pop();
        int xo=tmp.x,yo=tmp.y;
        for(int i=0;i<4;i++){
            int x=xo+dx[i],y=yo+dy[i];

            if(x>=1 && x<=n && y>=1 && y<=m && mapp[x][y]==-1){
                mapp[x][y]=mapp[xo][yo]+1;

                P1332 nxt;
                nxt.x=x;
                nxt.y=y;
                q.push(nxt);
            }
        }
    }
}

int main(){
    cin>>n>>m>>a>>b;
    memset(mapp,-1,sizeof(mapp));
    for(int i=1;i<=a;i++){
        cin>>ap[i].x>>ap[i].y;
        mapp[ap[i].x][ap[i].y]=0;
        q.push(ap[i]);
    }
    bfs();
    for(int i=1;i<=b;i++){
        cin>>bp[i].x>>bp[i].y;
        cout<<mapp[bp[i].x][bp[i].y]<<'\n';
    }
}