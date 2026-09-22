#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=505;

int n;
int a[N],f[N][N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)f[i][i]=1;
    for(int i=1;i+1<=n;i++){
        int j=i+1;
        if(a[i]==a[j])f[i][j]=1;
        else f[i][j]=2;
    }

    for(int len=3;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=len+i-1;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
            }
            if(a[i]==a[j])f[i][j]=min(f[i+1][j-1],f[i][j]);
        }
    }

    cout<<f[1][n];
}