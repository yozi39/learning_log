#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define qp '\n'

const int N=1e5+5;
const LL LINF=0x3f3f3f3f3f3f3f3f;
int n;
LL k,a[N],f[N][31];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=30;j++)f[i][j]=-LINF;
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++){
            if(f[i-1][j]==-LINF)continue;

            // 好钥匙：次数不变，支付k
            f[i][j]=max(f[i][j],f[i-1][j]+(a[i]>>j)-k);

            // 坏钥匙：再减半一次，不花钱
            int t=min(j+1,30);
            f[i][t]=max(f[i][t],f[i-1][j]+(a[i]>>t));
        }
    }
    LL ret=-LINF;
    for(int j=0;j<=30;j++)ret=max(ret,f[n][j]);
    cout<<ret<<qp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
}