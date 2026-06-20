#include<bits/stdc++.h>
using namespace std;

const int N=5010,INF=0x3f3f3f3f;

int n,m,edge[N][N];
int ans;

int dist[N],st[N];

int prim(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    int ret=0;
    //加入n个点
    for(int i=1;i<=n;i++){
        int t=0;
        //找到最近点;
        for(int j=1;j<=n;j++){
            if(!st[j] && dist[j]<dist[t]){
                t=j;
            }
        }

        //判断是否联通
        if(dist[t]==INF)return INF;
        ret+=dist[t];
        st[t]=1;

        //更新距离
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],edge[t][j]);
        }

    }
    return ret;
}

int main(){
    memset(edge,0x3f,sizeof edge);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[x][y]=edge[y][x]=min(edge[x][y],z);//要处理重边啊!!!
    }

    ans=prim();

    if(ans==INF){
        cout<<"orz";
    }
    else{
        cout<<ans;
    }
}

/*vector版本

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=5010,INF=0x3f3f3f3f;

int n,m;
vector<PII> a[N];
int ans;

int dist[N],st[N];

int prim(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    int ret=0;
    //加入n个点
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=n;j++){
            if(!st[j] && dist[j]<dist[t]){
                t=j;
            }
        }

        if(dist[t]==INF)return INF;
        ret+=dist[t];
        st[t]=1;

        for(auto& v:a[t]){
            int a=v.first,b=v.second;
            //a[t]  t->a  权值b;
            dist[a]=min(dist[a],b);
        }
    }
    return ret;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }

    ans=prim();

    if(ans==INF){
        cout<<"orz";
    }
    else{
        cout<<ans;
    }
}
*/