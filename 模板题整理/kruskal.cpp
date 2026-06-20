#include<bits/stdc++.h>
using namespace std;

const int N=5010,M=2e5+10,INF=0x3f3f3f3f;

int n,m;
int fa[N];

struct Node
{
    int x,y,z;
}a[M];

int find(int x){
    return fa[x]==x ? x:fa[x]=find(fa[x]);
}

bool cmp(Node& a,Node& b){
    return a.z<b.z;
}

int kruskal(){
    sort(a+1,a+1+m,cmp);

    int cnt=0,ret=0;
    for(int i=1;i<=m;i++){
        int x=a[i].x,y=a[i].y;

        int fx=find(x),fy=find(y);
        if(fx!=fy){
            cnt++;
            ret += a[i].z;
            fa[fx]=fy;
        }
    }
    return cnt==n-1 ? ret:INF;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    for(int i=1;i<=n;i++)fa[i]=i;

    int ret=kruskal();
    if(ret==INF){
        cout<<"orz";
    }
    else{
        cout<<ret;
    }
}