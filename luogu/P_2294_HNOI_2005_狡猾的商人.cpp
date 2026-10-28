#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 110, M = 3010;

int n, m;
int h[N], e[M], w[M], ne[M], id;
bool st[N];
int dist[N], cnt[N];

void add(int a,int b,int c){
    id++;
    e[id]=b;w[id]=c;ne[id]=h[a];h[a]=id;
}

bool spfa(){
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    q.push(n+1);
    dist[n+1] = 0;
    st[n+1] = true;

    while(q.size()){
        int x = q.front();q.pop();
        st[x] = false;

        for(int i=h[x];i;i=ne[i]){
            int y = e[i],z=w[i];
            if(dist[x]+z<dist[y]){
                dist[y] = dist[x] + z;
                cnt[y] = cnt[x] + 1;
                if(cnt[y] >= n+2)return true;
                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    memset(h, 0, sizeof h); id = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        add(b, a - 1, -c); add(a - 1, b, c);
    }

    for(int i = 0; i <= n; i++)
    {
        add(n + 1, i, 0);
    }

    if(spfa()){
        cout<<"false\n";
    } else {
        cout<<"true\n";
    }
}

int main()
{
    int T; cin >> T;

    while(T--) solve();

    return 0;
}