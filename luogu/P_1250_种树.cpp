#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 3e4 + 5,M=1e5+5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;

int e[M],ne[M],h[N],w[M],id;
void add(int a,int b,int c){
    id++;
    e[id] = b;w[id] = c;ne[id] = h[a];h[a] = id;
}

int dist[N],cnt[N];
bool st[N];
void spfa(){
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    st[n]=true;

    while (q.size())
    {
        auto x = q.front();q.pop();
        st[x] = false;

        for(int i=h[x];i;i=ne[i]){
            int y = e[i],z = w[i];
            if(dist[y] > dist[x] + z){
                dist[y] = dist[x]+z;
                cnt[y] = cnt[x] + 1;

                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){//-r+l+1<=-c;
        int l,r,w;cin>>l>>r>>w;
        add(r,l-1,-w);
    }
    for(int i=1;i<=n;i++){//i-(i-1) <= 1
        add(i-1,i,1);
        add(i,i-1,0);
    }

    memset(dist,0x3f,sizeof dist);
    spfa();

    cout<<-dist[0];
}