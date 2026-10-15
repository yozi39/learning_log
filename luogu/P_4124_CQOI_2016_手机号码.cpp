#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef __int128 LLL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;

#define qp '\n'

const int N=15;
const LL LINF=0x3f3f3f3f3f3f3f3f;
const int INF=0x3f3f3f3f;

int n,nn[N];
LL f[N][11][4][2][9];

LL dfs(int pos,bool limit,int pre,int len,bool ok,int only){
    if(!pos) return ok;

    if(!limit && ~f[pos][pre][len][ok][only])
        return f[pos][pre][len][ok][only];

    int up=limit?nn[pos]:9;
    int down=(pos==n?1:0);

    LL ret=0;
    for(int i=down;i<=up;i++){
        int no=only;

        if(i==4){
            if(no==8)continue;
            no=4;
        }
        if(i==8){
            if(no==4)continue;
            no=8;
        }

        int nl;
        if(i==pre) nl=min(3,len+1);
        else nl=1;

        bool nok=ok || (nl>=3);

        ret+=dfs(pos-1,
                 limit&&(i==nn[pos]),i,nl,nok,no);
    }

    if(!limit)
        f[pos][pre][len][ok][only]=ret;

    return ret;
}

LL calc(LL x){
    if(x<10000000000LL)return 0;

    n=0;
    memset(f,-1,sizeof f);

    while(x){
        nn[++n]=x%10;
        x/=10;
    }

    return dfs(n,1,10,0,0,0);
}

int main(){
    LL a,b;
    cin>>a>>b;

    cout<<calc(b)-calc(a-1)<<qp;
}