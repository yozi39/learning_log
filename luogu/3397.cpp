#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;

int a[N][N],f[N][N];
int xa,ya,xb,yb;

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>xa>>ya>>xb>>yb;
        for(int i=ya;i<=yb;i++){
            f[xa][i] += 1;
            f[xb+1][i] -= 1;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            a[j][i]=a[j-1][i]+f[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}