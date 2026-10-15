#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=20;

int n,nn[N];
LL f[N][N*9][N*9];
LL a,b;

LL dfs(int pos,bool limit,LL sum,LL target,int mod){
    if(!pos){
        if(mod==sum && target == 0) return 1;
        return 0;
    }
    if(~f[pos][sum][target] && !limit)return f[pos][sum][target];

    int up = limit? nn[pos]:9;
    LL ret=0;
    for(int i=0;i<=up;i++){
        ret+=dfs(pos-1,limit&&(nn[pos]==i),sum+i,((target*10)+i)%mod,mod);
    }

    if(!limit)f[pos][sum][target] = ret;
    return ret;
}

LL calc(LL x){
    n=0;
    
    while(x){
        nn[++n] = x%10;
        x/=10;
    }

    LL ret=0;
    for(int m=1;m<=n*9;m++){
        memset(f,-1,sizeof f);
        ret+=dfs(n,1,0,0,m);
    }
    return ret;
}

int main(){
    LL a,b;
    cin>>a>>b;
    cout<<calc(b)-calc(a-1);
}