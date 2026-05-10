#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e3+10;
int n,m,st[N][N],ansn[N][N];
string pan[N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(PII point){
    queue<PII> q;
    vector<PII> path;   
    point.first--;
    point.second--;     

    q.push(point);
    st[point.first][point.second]=1;
    path.push_back(point);
    int ans=1;
    while(q.size()){
        auto tmp=q.front();q.pop();
        int xo=tmp.first,yo=tmp.second;
        for(int i=0;i<4;i++){
            int x=xo+dx[i],y=yo+dy[i];

            if(x>=0 && x<n && y>=0 && y<n &&
               pan[x][y] != pan[xo][yo] &&
               st[x][y]==-1){

                ans++;
                st[x][y]=1;
                q.push({x,y});
                path.push_back({x,y});
            }
        }
    }
    for(auto t:path){
        ansn[t.first][t.second]=ans;
    }
    return ans;
}

int main(){
    cin>>n>>m;
    memset(st,-1,sizeof(st));  
    for(int i=0;i<n;i++) cin>>pan[i];
    for(int i=0;i<m;i++){
        PII tmp;
        cin>>tmp.first>>tmp.second;
        int a=tmp.first-1;
        int b=tmp.second-1;
        if(ansn[a][b]!=0){
            cout<<ansn[a][b];
        }
        else{
            cout<<bfs(tmp);
        }
        cout<<'\n';
    }
}