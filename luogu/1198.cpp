#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2e5+5;

LL t,pos;
int m,d;
LL f[N][25];
int lg[N];

void init(){
    lg[0]=-1;
    for(int i=1;i<=N-1;i++){
        lg[i]=lg[i>>1]+1;
    }
}

void add(LL x){
    f[++pos][0]=(x+t)%d;
    for(int j=1;j<=lg[pos];j++){
        f[pos-(1<<j)+1][j]=max(f[pos-(1<<j)+1][j-1],f[pos-(1<<(j-1))+1][j-1]);
    }
}

LL query(LL x){
    int k=lg[x];
    int l=pos-x+1;
    return max(f[l][k],f[pos-(1<<k)+1][k]);
}

int main(){
    cin>>m>>d;
    
    init();

    while (m--)
    {
        char op;
        LL x;
        cin>>op>>x;

        if(op == 'A'){
            add(x);
        } else {
            t=query(x);
            cout<<t<<'\n';
        }
    }
}