//P4799
//总结:一个触发点就是N=40~46和区间dp一样很吃N
//都是2^N的时间复杂度
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 45;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

//RE:空间问题,这里要一个M用来给b,因为遍历出来会有很多不同的子集
const int M = 1100000;
LL n,m;
LL ret;
LL a[N];
LL b[M],cnt;
int mid;

void ldfs(int pos,LL sum){
    if(pos>mid){
        b[++cnt] = sum;
        return;
    }

    ldfs(pos+1,sum);
    ldfs(pos+1,sum+a[pos]);
}

void rdfs(int pos,LL sum){
    if(pos>n){
        ret += upper_bound(b+1,b+1+cnt,m-sum)-(b+1);
        return;
    }

    rdfs(pos+1,sum);
    rdfs(pos+1,sum+a[pos]);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    mid = (1+n)/2;
    ldfs(1,0);
    sort(b+1,b+1+cnt);
    rdfs(mid+1,0);

    cout<<ret;
}