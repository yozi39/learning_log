#include<bits/stdc++.h>
using namespace std;

const int N=105,M=1005;
int n,m,x;
int a[N],b[N],c[N];
int f[M][M];

int main(){
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];

    for(int i=1;i<=n;i++){
        for(int j=x;j>=c[i];j--){
            for(int k=m;k>=b[i];k--){
                f[j][k]=max(f[j][k],f[j-c[i]][k-b[i]]+a[i]);
            }
        }
    }
    cout<<f[x][m];
}