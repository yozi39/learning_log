#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e5 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL h,dist[N];
int a[4],m=INF;

int main(){
    cin>>h>>a[1]>>a[2]>>a[3];
    for(int i=1;i<=3;i++)m = min(m,a[i]);

    memset(dist,INF,sizeof dist);
    dist[0] = 0;
    for(int i=1;i<=3;i++){
        if(a[i] == m)continue;
        int d = __gcd(a[i],m);
        
        for(int j=0;j<d;j++){
            for(int x = j,c=0;c<2;c+=(x == j)){
                int y = (x + a[i])%m;
                dist[y] = min(dist[y],dist[x] + a[i]);
                x = y;
            }
        }
    }

    --h;
    LL ret = 0;
    for(int i=0;i<m;i++){
        if(dist[i]==LINF || dist[i]>h)continue;
        ret += (h-dist[i])/m+1;
    }
    cout<<ret;
}