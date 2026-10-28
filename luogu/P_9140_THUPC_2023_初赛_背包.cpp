#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e5 + 5,M = 55;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const LL INF = -1e15;

LL n,q;
LL f[N];
LL v[M],c[M],m = N,w;

void circle(){
    for(int i=1;i<=m-1;i++)f[i] = INF;

    for(int i=1;i<=n;i++){
        if(v[i]==m)continue;
        int d = __gcd(v[i],m);
        for(int j=0;j<d;j++){
            for(int x = j,cnt=0;cnt<2;cnt+=(x==j)){
                int y = (x + v[i])%m;
                if(f[x]!=INF)f[y] = max(f[y],f[x] + c[i]-(v[i]+x)/m*w);
                x = y;
            }
        }
    }
}

int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>c[i];
        if(w*v[i]<m*c[i])w=c[i],m=v[i];
    }

    circle();

    while (q--){
        LL V;cin>>V;
        LL t = V%m;

        if(f[t] == INF)cout<<-1<<qp;
        else cout<<(V/m*w+f[t])<<qp;
    }
}