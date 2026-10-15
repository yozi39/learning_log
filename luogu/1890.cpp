#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=1e3+5;

int n,m;
LL f[N][20];
int lg[N];

LL gcd(LL a,LL b){
    return b==0? a:gcd(b,a%b);
}

void init(){
    lg[0]=-1;
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        cin>>f[i][0];
    }

    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<(j-1))-1<=n;i++){
            f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}

LL RMQ(int l,int r){
    int k=lg[r-l+1];
    return gcd(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    cin>>n>>m;

    init();

    while(m--){
        int l,r;cin>>l>>r;

        cout<<RMQ(l,r)<<'\n';
    }
}