#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e3 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,c[N],ret;
int r[55];
vector<PII> edge[N];

void build(int k){
    for(int i=0;i<=24;i++)edge[i].clear();
    for(int i=1;i<=24;i++){
        edge[i-1].push_back({i,0});
        edge[i].push_back({i-1,-c[i]});
    }

    for(int i=1;i<=7;i++){
        edge[i+16].push_back({i,r[i]-k});
    }
    for(int i=8;i<=24;i++){
        edge[i-8].push_back({i,r[i]});
    }
    edge[0].push_back({24,k});
    edge[24].push_back({0,-k});
}

int dist[N],cnt[N];
bool st[N];
bool spfa(int x){
    memset(dist,-0x3f,sizeof dist);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    st[x] = true;

    while(q.size()){
        auto x = q.front();q.pop();
        st[x] = false;

        for(auto t:edge[x]){
            int y = t.first,z=t.second;
            if(dist[y]<dist[x]+z){
                dist[y] = dist[x]+z;
                cnt[y] = cnt[x]+1;

                if(cnt[y]>=25)return true;
                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
    return false;
}

int main(){
    int T;cin>>T;
    while(T--){
        memset(c,0,sizeof c);
        ret = -1;
        for(int i=1;i<=24;i++){
            cin>>r[i];
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            int t;cin>>t;t++;
            c[t]++;
        }

        for(int k=0;k<=n;k++){
            build(k);
            if(!spfa(0)){
                ret = k;
                break;
            }
        }

        if(ret == -1)cout<<"No Solution"<<qp;
        else cout<<ret<<qp;
    }
}