#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 50,M=67200000;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

LL w,ret;
int n;
int mid;
LL g[N],t[M],cnt;

void ldfs(int pos,LL sum){
    if(sum>w) return;

    if(pos>mid){
        t[++cnt] = sum;
        return;
    }

    ldfs(pos+1,sum);
    ldfs(pos+1,sum+g[pos]);
}

void rdfs(int pos,LL sum){
    if(sum>w) return;
    
    if(pos>n){
        ret = max(ret,sum+t[upper_bound(t+1,t+1+cnt,w-sum)-t-1]);
        return;
    }

    rdfs(pos+1,sum);
    rdfs(pos+1,sum+g[pos]);
}

int main(){
    cin>>w>>n;
    for(int i=1;i<=n;i++)cin>>g[i];
    mid = (1+n)/2;

    ldfs(1,0);
    sort(t+1,t+1+cnt);
    rdfs(mid+1,0);

    cout<<ret;
}