#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define qp '\n'

const int N=25;

int n,m,a,b;
bool st[N][N];
LL memo[N][N];

int dx[9]={0,1,1,-1,-1,2,2,-2,-2};
int dy[9]={0,2,-2,2,-2,1,-1,1,-1};

LL dfs(int x,int y){
    if(x>n||y>m||st[x][y])return 0;

    if(x==n&&y==m)return 1;

    if(memo[x][y]!=-1)return memo[x][y];

    LL ret=0;
    ret+=dfs(x+1,y);
    ret+=dfs(x,y+1);

    return memo[x][y]=ret;
}

int main(){
    cin>>n>>m>>a>>b;

    for(int i=0;i<9;i++){
        int x=a+dx[i],y=b+dy[i];
        if(x>=0&&x<=n&&y>=0&&y<=m)
            st[x][y]=true;
    }

    memset(memo,-1,sizeof memo);

    cout<<dfs(0,0)<<qp;
}