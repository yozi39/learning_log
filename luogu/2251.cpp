#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e5+5;

int n,m;
LL f[N][25];
int lg[N];

void init(){
    lg[0]=-1;
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        cin>>f[i][0];
    }

    for(int j=1;j<=lg[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}

LL RMQ(int x){
    int k=lg[m];
    int l=x-m+1;
    return min(f[l][k],f[x-(1<<k)+1][k]);
}

int main(){
    cin>>n>>m;
    
    init();

    for(int i=m;i<=n;i++){
        cout<<RMQ(i)<<'\n';
    }
}