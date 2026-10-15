#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 10,M=155,T=3375005;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n,m;
int mid;
LL ret;
LL k[N],p[N],t[T],cnt;

LL qpow(int a,int b){
    LL ret = 1;
    while(b){
        if(b&1)ret *= a;
        b>>=1;
        a *= a;
    }
    return ret;
}

void ldfs(int pos,LL sum){
    if(pos>mid){
        t[++cnt] = sum;
        return;
    }

    for(int i=1;i<=m;i++){
        ldfs(pos+1,sum+(k[pos]*qpow(i,p[pos])));
    }
}

void rdfs(int pos,LL sum){
    if(pos>n){
        ret += upper_bound(t+1,t+1+cnt,-sum) - lower_bound(t+1,t+1+cnt,-sum);
        return;
    }

    for(int i=1;i<=m;i++){
        rdfs(pos+1,sum+(k[pos]*qpow(i,p[pos])));
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i]>>p[i];
    }    

    mid = (1+n)/2;
    ldfs(1,0);
    sort(t+1,t+1+cnt);
    rdfs(mid+1,0);

    cout<<ret;
}