//3385,bellman ford
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=2e3+10,INF=0x3f3f3f3f;

vector<PII> edge[N];
int n,T,m;

int dist[N];
void bf(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    bool flag=false;

    for(int i=1;i<=n;i++){
        flag=false;
        for(int j=1;j<=n;j++){
            if(dist[j] != INF){
                for(auto& y:edge[j]){
                    int a=y.first,b=y.second;
                    if(dist[a]>dist[j]+b){
                        dist[a]=dist[j]+b;
                        flag=true;
                    }
                }
            }
        }
        if(!flag){
            cout<<"NO"<<'\n';
            return;
        }
    }

    if(flag)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)edge[i].clear();
        for(int i=1;i<=m;i++){
            int a,b,c;cin>>a>>b>>c;
            if(c>=0){
                edge[b].push_back({a,c});    
                edge[a].push_back({b,c});
            }
            else edge[a].push_back({b,c});           
        }

        bf();
    }
}


//spfa

