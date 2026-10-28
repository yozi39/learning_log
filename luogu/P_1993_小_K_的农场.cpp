#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 5e3 + 5,M=1e4+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int e[M],h[N],ne[M],w[M],id;

void add(int a,int b,int c){
    id++;
    e[id] = b;w[id] = c;
    ne[id] = h[a];h[a] = id;
}

int dist[N],cnt[N];
bool st[N];
bool spfa(){
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    st[0] = true;

    while(q.size()){
        auto x = q.front();q.pop();
        st[x] = false;

        for(int i = h[x];i;i=ne[i]){
            int y = e[i],z = w[i];
            if(dist[y]>dist[x]+z){
                dist[y] = dist[x]+z;
                cnt[y] = cnt[x] + 1;
                if(cnt[y]>n+1){
                    return true;
                }

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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int op;cin>>op;
        int a,b,k;cin>>a>>b;
        if(op == 1){
            cin>>k;
            add(a,b,-k);
        } if(op == 2){
            cin>>k;
            add(b,a,k);
        } if(op == 3){
            add(b,a,0);
            add(-b,-a,0);
        }
    }
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }

    if(spfa()){
        cout<<"No";
    } else {
        cout<<"Yes";
    }
}