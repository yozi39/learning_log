#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1000 + 5,M=3e4+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,ml,md;

int h[N],e[M],ne[M],w[M],id;
void add(int a,int b,int c){
    id++;
    e[id]=b;w[id]=c;ne[id]=h[a];h[a]=id;
}

int dist[N],cnt[N];
bool st[N];
bool spfa(int s){
    memset(dist,0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    queue<int> q;
    q.push(s);
    dist[s]=0;
    st[s]=true;

    while(q.size()){
        int x=q.front();q.pop();
        st[x]=false;
        for(int i=h[x];i;i=ne[i]){
            int y=e[i],z=w[i];
            if(dist[y]>dist[x]+z){
                dist[y]=dist[x]+z;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n+1)return true;
                if(!st[y]){
                    q.push(y);
                    st[y]=true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>ml>>md;
    for(int i=1;i<=ml;i++){
        int a,b,c;cin>>a>>b>>c;
        add(a,b,c);
    }
    for(int i=1;i<=md;i++){
        int a,b,c;cin>>a>>b>>c;
        add(b,a,-c);
    }
    for(int i=1;i<n;i++){
        add(i+1,i,0);
    }
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }

    if(spfa(0)){
        cout<<-1<<qp;
    } else {
        spfa(1);
        if(dist[n]==INF)cout<<-2<<qp;
        else cout<<dist[n]<<qp;
    }
}