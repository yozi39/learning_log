#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e4+10,INF=2147483647;
int n,m,s;
queue<int> q;
vector<PII> edge[N];

int dist[N],st[N];//标记哪些节点在队列中
void spfa(){
    for(int i=0;i<=n;i++)dist[i]=INF;
    q.push(s);
    dist[s]=0;
    st[s]=true;

    while(q.size()){
        auto t=q.front();q.pop();
        st[t]=false;
        for(auto& v:edge[t]){
            if(dist[v.first]>dist[t]+v.second){
                dist[v.first]=dist[t]+v.second;
                if(!st[v.first]){
                    q.push(v.first);
                    st[v.first]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
}

int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }

    spfa();
}