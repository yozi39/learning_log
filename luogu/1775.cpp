#include<bits/stdc++.h>
using namespace std;

const int N=305,MAXN=1e4;

int n;
int a[N],pre[N];
int f[N][N];

int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
    memset(f,0X3f,sizeof(f));
    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1]+a[i];
        f[i][i]=0;
    }


    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            for(int k=i;k<i+len-1;k++){
                f[i][i+len-1]=min(f[i][k]+f[k+1][i+len-1]+pre[i+len-1]-pre[i-1],f[i][len+i-1]);
            }
        }
    }
    cout<<f[1][n];
}