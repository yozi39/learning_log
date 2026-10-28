#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5,INF = 0x3f3f3f3f,M=6e6+5;

typedef long long LL;
typedef pair<LL,int> PII;
int n,m=INF;
LL l,r;
LL dist[N];
int a[20];

LL get(LL x){
    LL ret = 0;
    for(int i=0;i<m;i++){
        if(x < dist[i]) continue;

        ret += (x-dist[i])/m+1;
    }
    return ret;
}

int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])m = min(m,a[i]);
    }
    if(m==INF){cout<<0;return 0;}

    memset(dist,0x3f,sizeof dist);
    dist[0] = 0;
    
    for(int i=1;i<=n;i++){
        if(a[i] == m)continue;
        int d = __gcd(a[i],m);
        for(int j = 0;j<d;j++){
            for(int x = j,c=0;c<2;c += (x==j)){
                int y = (x + a[i])%m;
                dist[y] = min(dist[y],dist[x] + a[i]);
                x = y;
            }
        }
    }

    cout<<get(r)-get(l-1);
}