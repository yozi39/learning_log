#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=30;

int na,nb,aa[N],bb[N];
int f[N][10];

void init(LL a,LL b){
    na=nb=0;
    while(b){
        bb[++nb] = b%10;
        b/=10;
    }
    while (a)
    {
        aa[++na] = a%10;
        a/=10;
    }
    memset(f,-1,sizeof f);
}

LL dfs(int pos,bool limit,int pre,int target[]){
    if(!pos) return 1;

    if(!limit && ~f[pos][pre]) return f[pos][pre];

    int up=limit?target[pos]:9;
    LL ret=0;

    for(int i=pre;i<=up;i++){
        ret+=dfs(pos-1,limit&&(i==target[pos]),i,target);
    }

    return limit?ret:f[pos][pre]=ret;
}

int main(){
    LL a,b;
    while(cin>>a>>b){
        init(--a,b);
        LL cntb = dfs(nb,1,0,bb);
        LL cnta = dfs(na,1,0,aa);

        cout<<cntb-cnta<<'\n';
    }
}