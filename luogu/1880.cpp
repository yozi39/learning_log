#include<bits/stdc++.h>
using namespace std;

const int N=205;
int n,f[N][N],g[N][N];
int pre[N],a[N];

int main(){
    cin>>n;
    memset(f,0x3f,sizeof(f));
    memset(g,-0x3f,sizeof(g));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }

    for(int i=1;i<=2*n;i++){
        pre[i]=pre[i-1]+a[i];
        f[i][i]=0;
        g[i][i]=0;
    }

    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int j=i+len-1;
            int add=pre[j]-pre[i-1];

            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+add);
                g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]+add);
            }
        }
    }

    int ans=-0x3f3f3f3f,ret=0x3f3f3f3f;
    for(int i=1;i+n-1<=2*n;i++){
        ans=max(ans,g[i][i+n-1]);
        ret=min(ret,f[i][i+n-1]);
    }
    cout<<ret<<'\n'<<ans;
}