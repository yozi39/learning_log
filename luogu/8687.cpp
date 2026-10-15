#include<bits/stdc++.h>
using namespace std;

const int N=105,M=21;

int n,m,k;
int c[N];
long long f[(1<<M)];

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int x;cin>>x;x--;
            c[i]|=(1<<x);//错在了用+,不是说不行但是有重复味道就不行
        }
    }

    memset(f,0x3f,sizeof f);
    f[0] = 0;
    for(int st = 0;st<(1<<m);st++){
        for(int i = 1;i<=n;i++){
            f[st|c[i]] = min(f[st|c[i]],f[st]+1);
        }
    }

    long long ret = f[(1<<m)-1];
    if(ret<0x3f3f3f3f3f3f3f3fL)cout<<ret;//第一次m写成n了
    else cout<<-1;
}