#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=10;

int n,nn[N];
LL f[N];

LL dfs(int pos,bool limit,int pre){
    if(!pos) return 1;
    if(!limit && ~f[pos] && pre!=6) return f[pos];

    int up = limit? nn[pos]:9;
    LL ret = 0;
    for(int i=0;i<=up;i++){
        if(pre == 6 && i==2)continue;
        if(i == 4)continue;
        ret+=dfs(pos-1,limit&(i==nn[pos]),i);
    }

    return (pre==6 || limit)? ret:f[pos] = ret;
}

LL calc(LL x){
    n=0;
    memset(f,-1,sizeof f);
    while (x)
    {
        nn[++n] = x%10;
        x/=10;
    }
    
    return dfs(n,1,0);
}

int main(){
    int a,b;
    while (cin>>a>>b,a||b)
    {
        cout<<calc(b)-calc(a-1)<<'\n';
    }
}