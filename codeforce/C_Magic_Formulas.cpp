#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const LL N = 1e6 + 5;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

int n;
LL p[N],pre[N];
LL tmp[N],cnt;

int main(){
    cin>>n;
    pre[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        pre[i] = pre[i-1] ^ i;
    }

    for(int i=1;i<=n;i++){
        int time = n/i;
        int hor = (time&1? pre[i-1]:0);
        int tail = n%i;
        int tor = pre[tail];

        tmp[++cnt] = hor ^ tor;
    }

    LL ret = tmp[1];
    for(int i=2;i<=n;i++){
        ret ^= tmp[i];
    }
    for(int i=1;i<=n;i++){
        ret ^= p[i];
    }
    cout<<ret;
}