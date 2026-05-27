#include<bits/stdc++.h>
using namespace std;

const int N=2005;

int n;
int a[N];
int f[N][N];

int main(){
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];

    for(int len=1;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            f[i][i+len-1]=max(f[i+1][i+len-1]+(n-len+1)*a[i],f[i][i+len-2]+(n-len+1)*a[i+len-1]);
        }
    }
    cout<<f[1][n];
}