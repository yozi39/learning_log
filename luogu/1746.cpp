#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1010;
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
long long ans;
PII start,e;
queue<PII> q;
int mp[N][N];

void bfs(){
    q.push({start.first,start.second});
    mp[start.first][start.second]=-1;
    while(q.size()){
        auto t=q.front();q.pop();
        int a=t.first,b=t.second;

        for(int i=0;i<4;i++){
            int x=a+dx[i],y=b+dy[i];
            if(x>=1 && x<=n && y<=n && y>=1 && mp[x][y]==0){
                mp[x][y]=mp[a][b]-1;
                q.push({x,y});
            }
        }
    }

}

int main(){
    cin>>n;
    string tmp[n];
    for(int i=0;i<n;i++)
        cin>>tmp[i];
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]=tmp[i-1][j-1]-'0';
        }
    }
    
    cin>>start.first>>start.second;
    cin>>e.first>>e.second;

    bfs();

    cout<<abs(mp[e.first][e.second]+1);
}