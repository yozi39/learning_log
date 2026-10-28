#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e4 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;

int e[N],ne[N],h[N],w[N],id;
void add(int a,int b,int c){
    id++;
    e[id] = b;w[id] = c;ne[id] = h[a];h[a] = id;
}

int dist[N],cnt[N];
bool st[N];
bool spfa(){
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    st[0] = true;

    while (q.size())
    {
        int f = q.front();q.pop();
        st[f] = false;

        for(int i=h[f];i;i=ne[i]){
            int y = e[i],z=w[i];
            if(dist[y] > dist[f] + z){
                dist[y] = dist[f] + z;
                cnt[y] = cnt[f]+1;
                if(cnt[y] >= n+1){
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
        int a,b,c;cin>>a>>b>>c;
        add(b,a,c);
    }
    for(int i=1;i<=n;i++){
        add(0,i,0);
    }

    memset(dist,0x3f,sizeof dist);

    if(spfa()){
        cout<<"NO";
    } else {
        for(int i=1;i<=n;i++)cout<<dist[i]<<' ';
    }
}