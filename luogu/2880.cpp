#include<bits/stdc++.h>
using namespace std;

const int N=5e+4+5;

int n,q;
int f[N][25],g[N][25];
int lg[N];

void init(){
    lg[0]=-1;
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        cin>>g[i][0];
        f[i][0]=g[i][0];
    }

    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
        }
    }
}

void RMQ(int l,int r)
{
    int k=lg[r-l+1];
    cout<<max(f[l][k],f[r-(1<<k)+1][k])-min(g[l][k],g[r-(1<<k)+1][k])<<'\n';
}

int main(){
    cin>>n>>q;

    init();

    while(q--){
        int l,r;
        cin>>l>>r;

        RMQ(l,r);
    }
}